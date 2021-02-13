#include <solar.h>
#include <string>
using namespace Solar;

// Define values for window
#define WIDTH 800
#define HEIGHT 600
#define BACKGROUND_COLOR Color32(34, 40, 49)

// Define values for player
#define PLAYER_COLOR Color32(238, 238, 238)
#define PLAYER_SCALE Vector2(20.0f, 80.0f)
#define PLAYER_SPEED 8.0f

// Define values for ball
#define BALL_COLOR Color32(0, 173, 181)
#define BALL_SCALE Vector2(20.0f, 20.0f)
#define BALL_SPEED 6.0f

// Define values for divider
#define DIVIDER_COLOR Color32(57, 62, 70)
#define DIVIDER_SCALE Vector2(10.0f, (double)HEIGHT - 100.0f)

// Define values for handling game state
bool game_started = false;
bool game_over = false;

// Player 1 definitions
Square player1 = Square(Transform(Vector2(-(double)WIDTH / 2.0f + 50.0f, 0.0f), 0.0f, PLAYER_SCALE), true, PLAYER_COLOR.Normalize(), true);
unsigned int player1_score = 0;
Text player1_score_text = Text("0", PLAYER_COLOR.Normalize(), Transform::Default(), Font("./resources/default_font.ttf", 0, 30));

// Player 2 definitions
Square player2 = Square(Transform(Vector2((double)WIDTH / 2.0f - 50.0f, 0.0f), 0.0f, PLAYER_SCALE), true, PLAYER_COLOR.Normalize(), true);
unsigned int player2_score = 0;
Text player2_score_text = Text("0", PLAYER_COLOR.Normalize(), Transform::Default(), Font("./resources/default_font.ttf", 0, 30));

// Ball definitions
Square ball = Square(Transform(Vector2::Zero(), 0.0f, BALL_SCALE), true, BALL_COLOR.Normalize());
Vector2 ball_movement = Vector2::Right() * BALL_SPEED;

// Divider definitions
Square divider = Square(Transform(Vector2::Zero(), 0.0f, DIVIDER_SCALE), true, DIVIDER_COLOR.Normalize());

// Starting text definition
Text start_text = Text("Press Space to start game", Color::White(), Transform::Default(), Font("./resources/default_font.ttf", 0, 24));
// Winner text definition
Text winner_text = Text("", Color::White(), Transform::Default(), Font("./resources/default_font.ttf", 0, 24));
// Text for displaying frame rate
Text frame_rate_text = Text("", Color::White(), Transform::Default(), Font("./resources/default_font.ttf", 0, 12));

void Reset()
{
	// Reset player position
	player1.transform.position = Vector2(-(double)WIDTH / 2.0f + 50.0f, 0.0f);
	player2.transform.position = Vector2((double)WIDTH / 2.0f - 50.0f, 0.0f);

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

	// Set viewport background color
	this->viewport.background_color = BACKGROUND_COLOR.Normalize();

	// Set initial player score text values
	player1_score_text.transform.position = Vector2(-(double)WIDTH / 2.0f + 150.0f, (double)HEIGHT / 2.0f - 100.0f);
	player2_score_text.transform.position = Vector2((double)WIDTH / 2.0f - 150.0f, (double)HEIGHT / 2.0f - 100.0f);

	// Set initial start text values
	start_text.transform.position = Vector2(-175.0f, 100.0f);
	// Set initial winner text values
	winner_text.transform.position = Vector2(-300.0f, 100.0f);
	// Set initial frame rate text values
	frame_rate_text.transform.position = Vector2(-(double)WIDTH / 2.0f, -(double)HEIGHT / 2.0f);
}

void App::Update(double frame_time)
{
	// If escape button pressed then exit game
	if (Input::OnPresetDown(Input::Presets::PresetEscape))
		App::Quit();
	if (Input::OnPresetDown(Input::Presets::PresetJump))
	{
		game_started = true;
		if (game_over) Reset();
	}

	frame_rate_text.message = std::to_string((int)(1.0f / frame_time));

	if (!game_started) return;
	if (game_over) return;

	// Move players with keyboard input
	player1.Move(Vector2(0.0f, (double)Input::IsKeyDown(Input::Keys::KeyW) - (double)Input::IsKeyDown(Input::Keys::KeyS)) * PLAYER_SPEED);
	player2.Move(Vector2(0.0f, (double)Input::IsKeyDown(Input::Keys::KeyUp) - (double)Input::IsKeyDown(Input::Keys::KeyDown)) * PLAYER_SPEED);

	// Move ball
	ball.Move(ball_movement);

	// Collisions will be handled by Solar in future versions
	// Manually checking for collisions for now

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