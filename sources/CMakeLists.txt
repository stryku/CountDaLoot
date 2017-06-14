set (inc
        ${inc_dir}/graphics/Image.hpp
		
        ${inc_dir}/loot/ILootObserver.hpp
        ${inc_dir}/loot/LootData.hpp
        ${inc_dir}/loot/TabLootReader.hpp
        ${inc_dir}/loot/LootTabProvider.hpp

        ${inc_dir}/structs/Pos.hpp
        ${inc_dir}/structs/Rect.hpp
        ${inc_dir}/structs/Rgba.hpp
		
                    
            PARENT_SCOPE)
					
set (src 
        ${src_dir}/graphics/Image.cpp
		
        ${src_dir}/loot/TabLootReader.cpp
            
            PARENT_SCOPE)