set (inc
        ${inc_dir}/capture/ScreenCapturer.hpp

        ${inc_dir}/graphics/Image.hpp
		
        ${inc_dir}/font/LootFont.hpp
		
        ${inc_dir}/loot/ILootObserver.hpp
        ${inc_dir}/loot/LootData.hpp
        ${inc_dir}/loot/TabLootReader.hpp
        ${inc_dir}/loot/LootTabProvider.hpp

        ${inc_dir}/structs/Pos.hpp
        ${inc_dir}/structs/Rect.hpp
        ${inc_dir}/structs/Rgba.hpp
        ${inc_dir}/structs/Size.hpp
		
                    
            PARENT_SCOPE)
					
set (src 
        ${src_dir}/capture/ScreenCapturer.cpp

        ${src_dir}/graphics/Image.cpp

        ${src_dir}/font/LootFont.cpp
		
        ${src_dir}/loot/TabLootReader.cpp
            
            PARENT_SCOPE)