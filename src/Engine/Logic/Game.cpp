#include "Game.h"
#include "GameState.h"

Texture test;

Game::Game()
{
}

void Game::Init(int w, int h)
{
    Game::m_bRunning = true;
    displayManager.init(w, h);
    printf("Game Initialised Succesfully\n");
}

/*
Our new functions, ChangeState() takes a pointer to a GameState as a parameter and then pushes that state onto the vector of pointers to GameStates, before that it uses the clean function to remove the old state from the stack.
*/
void Game::ChangeState(GameState *state)
{
    if (!states.empty())
    {
        states.back()->Clean();
        states.pop_back();
    }
    states.push_back(state);
    state->Init();
}

/*
Whereas ChangeState() pushes a state onto the stack and removes the previous state, PushState() pauses the previous state before pushing a new state onto the stack, this state can then be removed and the previous state resumed. Extrememly useful for pausing.
*/
void Game::PushState(GameState *state)
{
    if (!states.empty())
    {
        states.back()->Pause();
    }
    states.push_back(state);
    states.back()->Init();
}

/*
    Remove and resume previous state.
*/
void Game::PopState()
{
    if (!states.empty())
    {
        states.back()->Clean();
        states.pop_back();
    }

    if (!states.empty())
    {
        states.back()->Resume();
    }
}

bool Game::Running()
{
    return Game::m_bRunning;
}

/*
These functions have now been changed so that they simply allow the current state to handle things, states.back() refers to the last element on the stack (the current state)
*/
void Game::HandleEvents()
{
    // let the state handle events
    states.back()->HandleEvents(this);
}

void Game::Update()
{
    // let the state update the game
    states.back()->Update(this);
}

void Game::Draw()
{
    // let the state draw the screen
    states.back()->Draw(this);
}

void Game::Quit()
{
    Game::m_bRunning = false;
}

void Game::Clean()
{
    while (!states.empty())
    {
        states.back()->Clean();
        states.pop_back();
    }
    SDL_Quit();
}