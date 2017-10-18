#include "Game.h"

GameScreen::GameScreen() : Scene ()
{
	// we initialize data
	Start();
}

GameScreen::~GameScreen()
{
	m_bgm->stop();
	m_sfx->stop();
	delete m_bgm;
	delete m_sfx;
	pp2d_free_texture(TEXTURE_SPRITESHEET_ID);
}

void GameScreen::Start()
{
	// We will use 2 channels for sounds: 1 = BGM, 2= Sound effects so they can be played at same time. You can set as channels as you want.

	// We clear the channels
	ndspChnWaveBufClear(1);
	ndspChnWaveBufClear(2);

	// We initialize our game variables
	m_offset = 0;
	m_playerX = TOP_WIDTH / 2;
	m_playerY = HEIGHT / 2; 

	// We load our images and place them into RAM so they can be painted
	pp2d_load_texture_png(TEXTURE_SPRITESHEET_ID2, IMG_SPRITES);

	// We load our sounds // PATH, CHANNEL, LOOP? -> // BGM plays with loop, but sfx just one time
	m_bgm = new sound(SND_BGM_GAME, 1, true);		
	m_sfx = new sound(SND_SFX_TAP, 2, false);

	// We play our bgm
	m_bgm->play();
}

void GameScreen::Draw()
{	
	//PP2D HAS NO 3D Effect yet
	pp2d_begin_draw(GFX_TOP, GFX_LEFT);
	pp2d_draw_texture_part(TEXTURE_SPRITESHEET_ID2, 0, 0, TOP_WIDTH, 0, TOP_WIDTH, HEIGHT);
	pp2d_draw_texture_part(TEXTURE_SPRITESHEET_ID2, m_playerX, m_playerY, 0, HEIGHT*2, 90, 96);
	pp2d_draw_text(15, 5, 0.6f, 0.6f, C_WHITE, "HELLO WORLD!!");

	// Bottom screen (We just show an image)
	pp2d_draw_on(GFX_BOTTOM, GFX_LEFT);
	pp2d_draw_texture_part(TEXTURE_SPRITESHEET_ID2, 0, 0, TOP_WIDTH, HEIGHT, BOTTOM_WIDTH, HEIGHT);
	pp2d_end_draw();
}

void GameScreen::Update()
{
	// Things that happens in your game... update the player or something
}

void GameScreen::CheckInputs()
{
	hidScanInput();

	
	if ((hidKeysDown() & KEY_UP))
	{
		m_playerY--;
	}

	if ((hidKeysDown() & KEY_DOWN))
	{
		m_playerY++;
	}

	if ((hidKeysDown() & KEY_RIGHT))
	{
		m_playerX++;
	}

	if ((hidKeysDown() & KEY_LEFT))
	{
		m_playerX--;
	}

	// We Exit pressing Select
	if ((hidKeysDown() & KEY_SELECT))
	{
		SceneManager::instance()->SaveDataAndExit();
		delete(this);
	}
}

