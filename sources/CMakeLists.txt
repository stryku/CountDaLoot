set (inc
        ${inc_dir}/CountDaLoot.hpp

        ${inc_dir}/capture/ScreenCapturer.hpp
        
        ${inc_dir}/consts/consts.hpp
        
        ${inc_dir}/data/DataProvider.hpp

        ${inc_dir}/graphics/Image.hpp
        
        ${inc_dir}/font/db/Character.hpp
        ${inc_dir}/font/db/CharacterDb.hpp
        
        ${inc_dir}/loot/ILootObserver.hpp
        ${inc_dir}/loot/ILootStatsObserver.hpp
        ${inc_dir}/loot/NewLootProvider.hpp
        ${inc_dir}/loot/LootFilter.hpp
        ${inc_dir}/loot/LootData.hpp
        ${inc_dir}/loot/KilledMonstersData.hpp
        
        ${inc_dir}/loot/parse/ParsedLootLine.hpp
        ${inc_dir}/loot/parse/LootLineParser.hpp

        ${inc_dir}/loot/tab/TabLootReader.hpp
        ${inc_dir}/loot/tab/LootTabCoordinates.hpp
        ${inc_dir}/loot/tab/LootTabProvider.hpp
        ${inc_dir}/loot/tab/LootTabFinder.hpp
        ${inc_dir}/loot/tab/ILootTabStateObserver.hpp
        ${inc_dir}/loot/tab/LootTabState.hpp
        ${inc_dir}/loot/tab/LootTabData.hpp

        ${inc_dir}/structs/Pos.hpp
        ${inc_dir}/structs/Rect.hpp
        ${inc_dir}/structs/Rgba.hpp
        ${inc_dir}/structs/Size.hpp
        
        ${inc_dir}/text/TextReader.hpp

        ${inc_dir}/thread/ThreadWorker.hpp

        ${inc_dir}/ui/controls/Table.hpp

        ${inc_dir}/view/LootListUpdater.hpp
        ${inc_dir}/view/LootListViewType.hpp
        ${inc_dir}/view/LootTabStateLabelUpdater.hpp
        
        ${inc_dir}/view/summary/MonsterMapSorter.hpp
        ${inc_dir}/view/summary/SummaryMonstersUpdater.hpp
        ${inc_dir}/view/summary/SummaryItemsUpdater.hpp
                    
            PARENT_SCOPE)
                    
set (src 
        ${src_dir}/CountDaLoot.cpp

        ${src_dir}/capture/ScreenCapturer.cpp
        
        ${src_dir}/consts/consts.cpp
        
        ${src_dir}/data/DataProvider.cpp

        ${src_dir}/graphics/Image.cpp
        
        ${src_dir}/font/db/Character.cpp
        ${src_dir}/font/db/CharacterDb.cpp

        ${src_dir}/loot/NewLootProvider.cpp
        ${src_dir}/loot/LootFilter.cpp
        ${src_dir}/loot/KilledMonstersData.cpp

        ${src_dir}/loot/parse/LootLineParser.cpp
        
        ${src_dir}/loot/tab/LootTabFinder.cpp
        ${src_dir}/loot/tab/LootTabProvider.cpp
        ${src_dir}/loot/tab/TabLootReader.cpp
        
        ${src_dir}/text/TextReader.cpp

        ${src_dir}/thread/ThreadWorker.cpp

        ${src_dir}/view/LootListUpdater.cpp
        ${src_dir}/view/LootTabStateLabelUpdater.cpp
        
        ${src_dir}/view/summary/MonsterMapSorter.cpp
        ${src_dir}/view/summary/SummaryMonstersUpdater.cpp
        ${src_dir}/view/summary/SummaryItemsUpdater.cpp
            
            PARENT_SCOPE)