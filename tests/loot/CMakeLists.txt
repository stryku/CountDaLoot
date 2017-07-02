set(dir ${test_src_dir}/loot)

set (test_loot_src 
        ${dir}/parse/LootLineParser.cpp
    )
            
set(TEST_SRC_FILES ${TEST_SRC_FILES} ${test_loot_src} PARENT_SCOPE)