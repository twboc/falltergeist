#pragma once

#include <vector>
#include <stdio.h>
#include <time.h>
#include "../../State/State.h"
#include "../../UI/Base.h"
#include "../../UI/Image.h"
#include "../../UI/ImageButton.h"
#include "../../UI/ImageList.h"
#include "../../UI/TextArea.h"
#include "../../Graphics/Size.h"
#include "../../Game/Game.h"
#include "../../Settings.h"
#include "../../Logger.h"
#include "../../Audio/Mixer.h"
#include "../../Input/Mouse.h"

#include <SDL.h>

namespace Falltergeist
{
    namespace UI
    {
        class Image;
        class ImageButton;
        class ImageList;
    }
    namespace State
    {
        class WorldMap : public State
        {
            public:

                WorldMap();
                ~WorldMap() override;

                void init() override;
                void render() override;
                void think() override;
                void handle(Event::Event* event) override;
                void onKeyDown(Event::Keyboard* event) override;
                void onStateActivate(Event::State* event) override;
                void onStateDeactivate(Event::State* event) override;
                void processInput();
                void exit();

                void setPanelOffset();

                void initHotspot();
                void renderHotspot();

                void initPanel();
                void renderPanel();

                void initTiles();
                void renderTiles();

                void setDelta();
                void correctDelta();
                void deltaNegativeToZero(int* delta);
                void deltaToMax(
                    signed int* delta,
                    signed int tilesNumber,
                    signed int tileDimension,
                    signed int mapDimension
                );

                bool inRenderView(
                    signed int worldTileMin,
                    signed int delta,
                    signed int tileDimension,
                    signed int mapDimension
                );

                void travel();
                int  setDestination(char orientation, unsigned int clickPosition);
                void preventTravelOutboundMin(float* nextPosition);
                void preventTravelOutboundMax(float* nextPosition, float currentPosition, int maxRange);

            private:
                //get keyboard state pointer
                const Uint8* keystate = SDL_GetKeyboardState(NULL);
                UI::ImageList* _tiles = nullptr;
                UI::ImageButton* _hotspot = nullptr;

                //panel
                UI::Image* _panel = nullptr;
                Graphics::Size panelSize;
                unsigned int panelX;
                unsigned int panelY;
                unsigned int fullscreenSidepanelWidth;
                unsigned int panelBorder = 22;

                // temporary!
                // @todo: move it to other place!
                // coordinates of the player on world map, has car
                float worldMapX = 0;
                float worldMapY = 0;
                float nextWorldMapX = 0;
                float nextWorldMapY = 0;
                bool hasCar = true;
                float directionHorizontal = 0;
                float directionVertical = 0;

                unsigned int destinationX = 0;
                unsigned int destinationY = 0;
                bool isTraveling = false;

                // map offset for fullscreen or windowed
                signed int offsetX = 0;
                signed int offsetY = 0;

                // delta (shift of map)
                signed int deltaX = 0;
                signed int deltaY = 0;

                // fallout2 map size: 4x5 tiles, so texture size is 1400x1500
                unsigned int tilesNumberX = 4; // fallout 2 tiles by X
                unsigned int tilesNumberY = 5; // fallout 2 tiles by Y
                unsigned int tileWidth = 350;  // fallout 2 map tile width
                unsigned int tileHeight = 300; // fallout 2 map tile height

                // default size data
                unsigned int mapWidth = 450;   // fallout 2 map screen width
                unsigned int mapHeight = 442;  // fallout 2 map screen height
                unsigned int mapMinX;      // start X point of map screen
                unsigned int mapMinY;      // start Y point of map screen

                const std::string sidePanelSprite = "art/intrface/wminfce2.frm";
                const std::string fullPanelSprite = "art/intrface/wmapbox.frm";

                std::vector<std::string> _worldMapTiles = {
                    "art/intrface/wrldmp00.frm",
                    "art/intrface/wrldmp01.frm",
                    "art/intrface/wrldmp02.frm",
                    "art/intrface/wrldmp03.frm",
                    "art/intrface/wrldmp04.frm",
                    "art/intrface/wrldmp05.frm",
                    "art/intrface/wrldmp06.frm",
                    "art/intrface/wrldmp07.frm",
                    "art/intrface/wrldmp08.frm",
                    "art/intrface/wrldmp09.frm",
                    "art/intrface/wrldmp10.frm",
                    "art/intrface/wrldmp11.frm",
                    "art/intrface/wrldmp12.frm",
                    "art/intrface/wrldmp13.frm",
                    "art/intrface/wrldmp14.frm",
                    "art/intrface/wrldmp15.frm",
                    "art/intrface/wrldmp16.frm",
                    "art/intrface/wrldmp17.frm",
                    "art/intrface/wrldmp18.frm",
                    "art/intrface/wrldmp19.frm"
                };
        };
    }
}