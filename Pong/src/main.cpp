#include <solar.h>
#include <string>
using namespace Solar;

// Values for window
#define WIDTH 800
#define HEIGHT 600
#define BACKGROUND_COLOR Color32(34, 40, 49)

// Values for player
#define PLAYER_COLOR Color32(238, 238, 238)
#define PLAYER_SCALE Vector2(20.0f, 80.0f)
#define PLAYER_SPEED 8.0f

// Values for ball
#define BALL_COLOR Color32(0, 173, 181)
#define BALL_SCALE Vector2(20.0f, 20.0f)
#define BALL_SPEED 5.0f

// Player 1 definitions
Square player1 = Square(PLAYER_COLOR.Normalize());
unsigned int player1_score = 0;
Text player1_score_text = Text("0", PLAYER_COLOR.Normalize(), Transform::Default(), Font("./resources/default_font.ttf", 0, 32));

// Player 2 definitions
Square player2 = Square(PLAYER_COLOR.Normalize());
unsigned int player2_score = 0;
Text player2_score_text = Text("0", PLAYER_COLOR.Normalize(), Transform::Default(), Font("./resources/default_font.ttf", 0, 32));

// Ball definitions
Square ball = Square(BALL_COLOR.Normalize());
Vector2 ball_movement = Vector2::Right() * BALL_SPEED;

Text text = Text("Press Space to start game", Color::White(), Transform::Default(), Font("./resources/default_font.ttf", 0, 24));

void App::Init()
{
	// Set window size
	App::SetWindowSize(WIDTH, HEIGHT);

	// Set window title
	App::SetWindowTitle("Pong");

	// Set initial player values
	player1.transform.scale = PLAYER_SCALE;
	player2.transform.scale = PLAYER_SCALE;

	player1.transform.position = Vector2(-(double)WIDTH / 2.0f + 50.0f, 0.0f);
	player2.transform.position = Vector2((double)WIDTH / 2.0f - 50.0f, 0.0f);

	player1.is_bounded = true;
	player2.is_bounded = true;

	// Set initial ball values
	ball.transform.scale = BALL_SCALE;

	text.transform.position.x = -175.0f;
	text.transform.position.y = 0.0f;

	player1_score_text.transform.position = Vector2(-(double)WIDTH / 2.0f + 100.0f, (double)HEIGHT / 2.0f - 100.0f);
	player2_score_text.transform.position = Vector2((double)WIDTH / 2.0f - 100.0f, (double)HEIGHT / 2.0f - 100.0f);
}

void App::Update(double frame_time)
{
	// If escape button pressed then exit game
	if (Input::OnPresetDown(Input::Presets::PresetEscape))
		App::Quit();

	// Move players with keyboard input
	player1.Move(Vector2(0.0f, (double)Input::IsKeyDown(Input::Keys::KeyW) - Input::IsKeyDown(Input::Keys::KeyS)) * PLAYER_SPEED);
	player2.Move(Vector2(0.0f, (double)Input::IsKeyDown(Input::Keys::KeyUp) - Input::IsKeyDown(Input::Keys::KeyDown)) * PLAYER_SPEED);

	// Move ball
	ball.Move(ball_movement);

	// Handle ball collisions
	// Ball colliding with vertical walls
	if (ball.transform.position.x + ball.transform.scale.x / 2.0f >= WIDTH / 2.0f)
	{
		ball.transform.position = Vector2();
		ball_movement.x = -ball_movement.x;
		ball_movement.y = Mathf::Random(-BALL_SPEED, BALL_SPEED);

		player1_score++;
		player1_score_text.message = std::to_string(player1_score);
	}
	else if (ball.transform.position.x - ball.transform.scale.x / 2.0f <= -WIDTH / 2.0f)
	{
		ball.transform.position = Vector2();
		ball_movement.x = -ball_movement.x;
		ball_movement.y = Mathf::Random(-BALL_SPEED, BALL_SPEED);

		player2_score++;
		player2_score_text.message = std::to_string(player2_score);
	}

	// Ball colliding with horizontal walls
	if (ball.transform.position.x + ball.transform.scale.x / 2.0f >= player2.transform.position.x - player2.transform.scale.x / 2.0f && ball.transform.position.x - ball.transform.scale.x / 2.0f <= player2.transform.position.x + player2.transform.scale.x / 2.0f)
	{
		if (ball_movement.x > 0.0f)
		{
			if (ball.transform.position.y + ball.transform.scale.y / 2.0f >= player2.transform.position.y - player2.transform.scale.y / 2.0f && ball.transform.position.y - ball.transform.scale.y / 2.0f <= player2.transform.position.y + player2.transform.scale.y / 2.0f)
			{
				ball_movement.x = -ball_movement.x;
				ball_movement.y = Mathf::Random(-BALL_SPEED, BALL_SPEED);
			}
		}
	}
	else if (ball.transform.position.x + ball.transform.scale.x / 2.0f >= player1.transform.position.x - player1.transform.scale.x / 2.0f && ball.transform.position.x - ball.transform.scale.x / 2.0f <= player1.transform.position.x + player2.transform.scale.x / 2.0f)
	{
		if (ball_movement.x < 0.0f)
		{
			if (ball.transform.position.y + ball.transform.scale.y / 2.0f >= player1.transform.position.y - player1.transform.scale.y / 2.0f && ball.transform.position.y - ball.transform.scale.y / 2.0f <= player1.transform.position.y + player1.transform.scale.y / 2.0f)
			{
				ball_movement.x = -ball_movement.x;
				ball_movement.y = Mathf::Random(-BALL_SPEED, BALL_SPEED);
			}
		}
	}

	if (ball.transform.position.y + ball.transform.scale.y / 2.0f >= HEIGHT / 2.0f || ball.transform.position.y - ball.transform.scale.y / 2.0f <= -HEIGHT / 2.0f)
		ball_movement.y = -ball_movement.y;
}

void App::Render()
{
	// Clear background color
	App::ClearBackground(BACKGROUND_COLOR.Normalize());

	// Render ball
	ball.Draw(*this, GameObject::DrawMode::kFill);

	// Render players
	player1.Draw(*this, GameObject::DrawMode::kFill);
	player2.Draw(*this, GameObject::DrawMode::kFill);

	// Render text
	text.Draw(*this);

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