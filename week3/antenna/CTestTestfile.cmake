# CMake generated Testfile for 
# Source directory: /home/eld/algolab/week3/antenna
# Build directory: /home/eld/algolab/week3/antenna
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(compilation_of__antenna "/usr/bin/cmake" "--build" "/home/eld/algolab/week3/antenna" "--target" "antenna")
set_tests_properties(compilation_of__antenna PROPERTIES  FIXTURES_SETUP "antenna" LABELS "antenna_")
add_test(execution___of__antenna "/home/eld/algolab/week3/antenna/antenna")
set_tests_properties(execution___of__antenna PROPERTIES  DEPENDS "compilation_of__antenna" FIXTURES_REQUIRED "antenna_;antenna" LABELS "antenna_" WORKING_DIRECTORY "/home/eld/algolab/week3/antenna/__exec_test_dir")
add_test(antenna__SetupFixture "/usr/bin/cmake" "-E" "copy_directory" "/home/eld/algolab/week3/antenna" "/home/eld/algolab/week3/antenna/__exec_test_dir")
set_tests_properties(antenna__SetupFixture PROPERTIES  FIXTURES_SETUP "antenna_" LABELS "antenna_")
add_test(antenna__CleanupFixture "/usr/bin/cmake" "-E" "remove_directory" "/home/eld/algolab/week3/antenna/__exec_test_dir")
set_tests_properties(antenna__CleanupFixture PROPERTIES  FIXTURES_CLEANUP "antenna_" LABELS "antenna_")
