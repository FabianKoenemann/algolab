# CMake generated Testfile for 
# Source directory: /home/eld/algolab/week4/pow_hiking_maps
# Build directory: /home/eld/algolab/week4/pow_hiking_maps
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(compilation_of__hiking_paths "/usr/bin/cmake" "--build" "/home/eld/algolab/week4/pow_hiking_maps" "--target" "hiking_paths")
set_tests_properties(compilation_of__hiking_paths PROPERTIES  FIXTURES_SETUP "hiking_paths" LABELS "pow_hiking_maps_")
add_test(execution___of__hiking_paths "/home/eld/algolab/week4/pow_hiking_maps/hiking_paths")
set_tests_properties(execution___of__hiking_paths PROPERTIES  DEPENDS "compilation_of__hiking_paths" FIXTURES_REQUIRED "pow_hiking_maps_;hiking_paths" LABELS "pow_hiking_maps_" WORKING_DIRECTORY "/home/eld/algolab/week4/pow_hiking_maps/__exec_test_dir")
add_test(pow_hiking_maps__SetupFixture "/usr/bin/cmake" "-E" "copy_directory" "/home/eld/algolab/week4/pow_hiking_maps" "/home/eld/algolab/week4/pow_hiking_maps/__exec_test_dir")
set_tests_properties(pow_hiking_maps__SetupFixture PROPERTIES  FIXTURES_SETUP "pow_hiking_maps_" LABELS "pow_hiking_maps_")
add_test(pow_hiking_maps__CleanupFixture "/usr/bin/cmake" "-E" "remove_directory" "/home/eld/algolab/week4/pow_hiking_maps/__exec_test_dir")
set_tests_properties(pow_hiking_maps__CleanupFixture PROPERTIES  FIXTURES_CLEANUP "pow_hiking_maps_" LABELS "pow_hiking_maps_")
