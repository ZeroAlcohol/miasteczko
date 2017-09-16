#include "catch.hpp"
#include "resources.textures.hpp"
#include "TextureContainer.hpp"
#include "GameObjectFactory.hpp"
#include "PassiveTexturedRectangle.hpp"
#include "Player.hpp"

TEST_CASE("should create suitable objects")
{
	Spirit::TextureContainer l_textureContainer{ rs::tx::flowerBox, rs::tx::player };

	SECTION("should create PassiveTexturedRectange")
	{
		LevelObjectData l_objectData
		{ 
			"flowerBox00", "passive-textured-rectangle", "idle", 50.0f, 50.0f, 0.0f 
		};
		const std::unique_ptr<IObject> l_passiveObject{ GameObjectFactory(l_textureContainer).createLevelObject(l_objectData) };	
		auto l_rawPasiveObject{ dynamic_cast<const PassiveTexturedRectangle *> (l_passiveObject.get()) };

		REQUIRE(nullptr != l_rawPasiveObject);
	}

	SECTION("should create Player")
	{
		LevelObjectData l_objectData
		{ 
			"player01", "player", "idle", 200.0f, 100.0f, 0.0f 
		};

		const std::unique_ptr<IObject> l_player{ GameObjectFactory(l_textureContainer).createLevelObject(l_objectData) };
		auto l_rawPlayer{ dynamic_cast<const Player *> (l_player.get()) };

		REQUIRE(nullptr != l_rawPlayer);
	}
}
