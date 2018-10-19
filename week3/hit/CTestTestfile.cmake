# CMake generated Testfile for 
# Source directory: /home/eld/algolab/week3/hit
# Build directory: /home/eld/algolab/week3/hit
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(compilation_of__hit "/usr/bin/cmake" "--build" "/home/eld/algolab/week3/hit" "--target" "hit")
set_tests_properties(compilation_of__hit PROPERTIES  FIXTURES_SETUP "hit" LABELS "hit_")
add_test(execution___of__hit "/home/eld/algolab/week3/hit/hit")
set_tests_properties(execution___of__hit PROPERTIES  DEPENDS "compilation_of__hit" FIXTURES_REQUIRED "hit_;hit" LABELS "hit_" WORKING_DIRECTORY "/home/eld/algolab/week3/hit/__exec_test_dir")
add_test(hit__SetupFixture "/usr/bin/cmake" "-E" "copy_directory" "/home/eld/algolab/week3/hit" "/home/eld/algolab/week3/hit/__exec_test_dir")
set_tests_properties(hit__SetupFixture PROPERTIES  FIXTURES_SETUP "hit_" LABELS "hit_")
add_test(hit__CleanupFixture "/usr/bin/cmake" "-E" "remove_directory" "/home/eld/algolab/week3/hit/__exec_test_dir")
set_tests_properties(hit__CleanupFixture PROPERTIES  FIXTURES_CLEANUP "hit_" LABELS "hit_")
