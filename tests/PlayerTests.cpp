#include "catch.hpp"
#include "Player.hpp"
#include "Animation.hpp"
#include <memory>

struct PlayerTestSuite
{
    PlayerTestSuite();
    std::shared_ptr<Player> m_player;
    std::shared_ptr<Animation> m_animation;
    std::pair<float, float> m_coordinates;

};

PlayerTestSuite::PlayerTestSuite()
{
    m_animation = std::make_shared<Animation>();
}


TEST_CASE_METHOD(PlayerTestSuite, "shouldReturnNameRobertWhenPlayerHasNameRobert" )
{
    m_player = std::make_shared<Player>("Robert", *m_animation, 5);
    REQUIRE("Robert" == m_player->getName());
}

TEST_CASE_METHOD(PlayerTestSuite, "shouldNotReturnNameRobertWhenPlayerHasNotNameRobert" )
{
    m_player = std::make_shared<Player>("Piotr", *m_animation, 5);
    REQUIRE("Robert" != m_player->getName());
}


