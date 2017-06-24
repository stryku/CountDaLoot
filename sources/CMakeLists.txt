set (inc
        ${inc_dir}/capture/ScreenCapturer.hpp
        
        ${inc_dir}/consts/consts.hpp
        
        ${inc_dir}/data/DataProvider.hpp

        ${inc_dir}/graphics/Image.hpp
        
        ${inc_dir}/font/db/Character.hpp
        ${inc_dir}/font/db/CharacterDb.hpp
        
        ${inc_dir}/loot/ILootObserver.hpp
        ${inc_dir}/loot/NewLootProvider.hpp
        ${inc_dir}/loot/LootFilter.hpp
        ${inc_dir}/loot/LootData.hpp
        
        ${inc_dir}/loot/tab/TabLootReader.hpp
        ${inc_dir}/loot/tab/LootTabCoordinates.hpp
        ${inc_dir}/loot/tab/LootTabProvider.hpp
        ${inc_dir}/loot/tab/LootTabFinder.hpp

        ${inc_dir}/structs/Pos.hpp
        ${inc_dir}/structs/Rect.hpp
        ${inc_dir}/structs/Rgba.hpp
        ${inc_dir}/structs/Size.hpp
        
        ${inc_dir}/text/TextReader.hpp

        ${inc_dir}/thread/ThreadWorker.hpp
        
                    
            PARENT_SCOPE)
                    
set (src 
        ${src_dir}/capture/ScreenCapturer.cpp
        
        ${src_dir}/consts/consts.cpp
        
        ${src_dir}/data/DataProvider.cpp

        ${src_dir}/graphics/Image.cpp
        
        ${src_dir}/font/db/Character.cpp
        ${src_dir}/font/db/CharacterDb.cpp

        ${src_dir}/loot/NewLootProvider.cpp
        ${src_dir}/loot/LootFilter.cpp
        
        ${src_dir}/loot/tab/LootTabFinder.cpp
        ${src_dir}/loot/tab/LootTabProvider.cpp
        ${src_dir}/loot/tab/TabLootReader.cpp
        
        ${src_dir}/text/TextReader.cpp

        ${src_dir}/thread/ThreadWorker.cpp 
            
            PARENT_SCOPE)