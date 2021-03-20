#include <solar.h>
#include <string>
using namespace Solar;

// Define values for window
#define WIDTH 800
#define HEIGHT 600
#define BACKGROUND_COLOR Color32(34, 40, 49).Normalize()

// Define values for players
#define PLAYER_COLOR Color32(238, 238, 238).Normalize()
#define PLAYER_SCALE Vector2(20.0f, 80.0f)
#define PLAYER_SPEED 500.0f
#define PLAYER1_INIT_POSITION Vector2(-(double)WIDTH / 2.0f + 50.0f, 0.0f)
#define PLAYER2_INIT_POSITION Vector2((double)WIDTH / 2.0f - 50.0f, 0.0f)

// Define values for ball
#define BALL_COLOR Color32(0, 173, 181).Normalize()
#define BALL_SCALE Vector2(20.0f, 20.0f)
#define BALL_SPEED 300.0f

// Define values for divider
#define DIVIDER_COLOR Color32(57, 62, 70).Normalize()
#define DIVIDER_SCALE Vector2(10.0f, (double)HEIGHT - 100.0f)

// Define values for handling game state
bool game_started = false;
bool game_over = false;

// Define values for player 1
Square player1 = Square(Transform(PLAYER1_INIT_POSITION, 0.0f, PLAYER_SCALE), PLAYER_COLOR);
unsigned int player1_score = 0;
Text player1_score_text = Text(Transform(Vector2(-(double)WIDTH / 2.0f + 150.0f, (double)HEIGHT / 2.0f - 100.0f), 0.0f, 1.0f), "0", PLAYER_COLOR, Font("./resources/default_font.ttf", 0, 30));

// Define values for player 2
Square player2 = Square(Transform(PLAYER2_INIT_POSITION, 0.0f, PLAYER_SCALE), PLAYER_COLOR);
unsigned int player2_score = 0;
Text player2_score_text = Text(Transform(Vector2((double)WIDTH / 2.0f - 150.0f, (double)HEIGHT / 2.0f - 100.0f), 0.0f, 1.0f), "0", PLAYER_COLOR, Font("./resources/default_font.ttf", 0, 30));

// Define values for ball
Square ball = Square(Transform(Vector2::Zero(), 0.0f, BALL_SCALE), BALL_COLOR);
Vector2 ball_movement = Vector2::Right() * BALL_SPEED;

// Define values for divider
Square divider = Square(Transform(Vector2::Zero(), 0.0f, DIVIDER_SCALE), DIVIDER_COLOR);

// Define starting text
Text start_text = Text(Transform(Vector2(-175.0f, 100.0f), 0.0f, 1.0f), "Press Space to start game", Color::White(), Font("./resources/default_font.ttf", 0, 24));
// Define winner text
Text winner_text = Text(Transform(Vector2(-300.0f, 100.0f), 0.0f, 1.0f), "", Color::White(), Font("./resources/default_font.ttf", 0, 24));
// Define text for displaying frame rate
Text frame_rate_text = Text(Transform(Vector2(-(double)WIDTH / 2.0f, -(double)HEIGHT / 2.0f), 0.0f, 1.0f), "", Color::White(), Font("./resources/default_font.ttf", 0, 12));

void Reset()
{
	// Reset player position
	player1.transform.position = PLAYER1_INIT_POSITION;
	player2.transform.position = PLAYER2_INIT_POSITION;

	// Reset player score
	player1_score = 0;
	player2_score = 0;

	// Reset player score text
	player1_score_text.message = std::to_string(player1_score);
	player2_score_text.message = std::to_string(player2_score);

	// Reset ball position
	ball.transform.position = Vector2();

	// Reset game over value
	game_over = false;
}

void App::Init()
{
	// Set window size
	App::SetWindowSize(WIDTH, HEIGHT);
	// Set window title
	App::SetWindowTitle("Pong");

	// Set player bounded in game window
	player1.is_bounded = true;
	player2.is_bounded = true;

	// Set viewport background color
	this->viewport.background_color = BACKGROUND_COLOR;

	// Set desired frame rate
	Time::SetTargetFrameRate(60);
}

void App::Update()
{
	// If escape button pressed then exit game
	if (Input::OnPresetDown(Input::Presets::PresetEscape))
		App::Quit();

	// Start or reset game on space input
	if (Input::OnPresetDown(Input::Presets::PresetJump))
	{
		game_started = true;
		if (game_over) Reset();
	}

	frame_rate_text.message = std::to_string(Time::FrameRate());

	if (!game_started) return;
	if (game_over) return;

	viewport.Move(Vector2((double)Input::IsKeyDown(Input::Keys::KeyRight) - (double)Input::IsKeyDown(Input::Keys::KeyLeft), 0.0f) * Time::FrameTime());

	// Move players with keyboard input
	player1.Move(Vector2(0.0f, (double)Input::IsKeyDown(Input::Keys::KeyW) - (double)Input::IsKeyDown(Input::Keys::KeyS)) * PLAYER_SPEED * Time::FrameTime());
	player2.Move(Vector2(0.0f, (double)Input::IsKeyDown(Input::Keys::KeyUp) - (double)Input::IsKeyDown(Input::Keys::KeyDown)) * PLAYER_SPEED * Time::FrameTime());

	// Move ball
	ball.Move(ball_movement * Time::FrameTime());

	// Collisions will be handled by Solar in future versions
	// Manually checking for collisions for now
	// Automatic collision detection will be added in future iterations

	// Ball colliding with vertical walls
	if (ball.transform.position.x + ball.transform.scale.x / 2.0f >= WIDTH / 2.0f)
	{
		// Reset ball position & movement
		ball.transform.position = Vector2();
		ball_movement.x = -ball_movement.x;
		ball_movement.y = Mathf::Random(-BALL_SPEED, BALL_SPEED);

		// Increment player score
		player1_score++;
		player1_score_text.message = std::to_string(player1_score);
	}
	else if (ball.transform.position.x - ball.transform.scale.x / 2.0f <= -WIDTH / 2.0f)
	{
		// Reset ball position & movement
		ball.transform.position = Vector2();
		ball_movement.x = -ball_movement.x;
		ball_movement.y = Mathf::Random(-BALL_SPEED, BALL_SPEED);

		// Increment player score
		player2_score++;
		player2_score_text.message = std::to_string(player2_score);
	}

	// Bal colliding with players
	if (ball.transform.position.x + ball.transform.scale.x / 2.0f >= player2.transform.position.x - player2.transform.scale.x / 2.0f && ball.transform.position.x - ball.transform.scale.x / 2.0f <= player2.transform.position.x + player2.transform.scale.x / 2.0f)
	{
		if (ball_movement.x > 0.0f)
		{
			if (ball.transform.position.y + ball.transform.scale.y / 2.0f >= player2.transform.position.y - player2.transform.scale.y / 2.0f && ball.transform.position.y - ball.transform.scale.y / 2.0f <= player2.transform.position.y + player2.transform.scale.y / 2.0f)
			{
				// Reset ball movement
				ball_movement.x = -ball_movement.x;
				ball_movement.y = Mathf::Random(-BALL_SPEED, BALL_SPEED);

				viewport.StartShaking(1.0f, 0.5f, 2.0f);
			}
		}
	}
	else if (ball.transform.position.x + ball.transform.scale.x / 2.0f >= player1.transform.position.x - player1.transform.scale.x / 2.0f && ball.transform.position.x - ball.transform.scale.x / 2.0f <= player1.transform.position.x + player2.transform.scale.x / 2.0f)
	{
		if (ball_movement.x < 0.0f)
		{
			if (ball.transform.position.y + ball.transform.scale.y / 2.0f >= player1.transform.position.y - player1.transform.scale.y / 2.0f && ball.transform.position.y - ball.transform.scale.y / 2.0f <= player1.transform.position.y + player1.transform.scale.y / 2.0f)
			{
				// Reset ball movement
				ball_movement.x = -ball_movement.x;
				ball_movement.y = Mathf::Random(-BALL_SPEED, BALL_SPEED);

				viewport.StartShaking(1.0f, 0.5f, 2.0f);
			}
		}
	}

	// Ball colliding with horizontal walls
	if (ball.transform.position.y + ball.transform.scale.y / 2.0f >= HEIGHT / 2.0f || ball.transform.position.y - ball.transform.scale.y / 2.0f <= -HEIGHT / 2.0f)
		ball_movement.y = -ball_movement.y;

	// Handle player winning event
	if (player1_score >= 5)
	{
		game_over = true;
		winner_text.message = "Player 1 wins. Press space to restart game";
	}
	else if (player2_score >= 5)
	{
		game_over = true;
		winner_text.message = "Player 2 wins. Press space to restart game";
	}
}

void App::Render()
{
	// Render divider
	divider.Draw(*this, GameObject::DrawMode::Fill);

	// Render ball
	ball.Draw(*this, GameObject::DrawMode::Fill);

	// Render players
	player1.Draw(*this, GameObject::DrawMode::Fill);
	player2.Draw(*this, GameObject::DrawMode::Fill);

	// Render start text
	if (!game_started) start_text.Draw(*this);
	// Render winner text
	if (game_over) winner_text.Draw(*this);
	// Render frame rate text
	frame_rate_text.Draw(*this);

	// Render score texts
	player1_score_text.Draw(*this);
	player2_score_text.Draw(*this);
}

void App::Exit()
{
}

int main()
{
	// Create a new app
	App* app = new App();
	// Run created app
	app->Run();
}