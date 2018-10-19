# CMake generated Testfile for 
# Source directory: /home/eld/algolab/week3/almost-antenna
# Build directory: /home/eld/algolab/week3/almost-antenna
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(compilation_of__almost_antenna "/usr/bin/cmake" "--build" "/home/eld/algolab/week3/almost-antenna" "--target" "almost_antenna")
set_tests_properties(compilation_of__almost_antenna PROPERTIES  FIXTURES_SETUP "almost_antenna" LABELS "almost-antenna_")
add_test(execution___of__almost_antenna "/home/eld/algolab/week3/almost-antenna/almost_antenna")
set_tests_properties(execution___of__almost_antenna PROPERTIES  DEPENDS "compilation_of__almost_antenna" FIXTURES_REQUIRED "almost-antenna_;almost_antenna" LABELS "almost-antenna_" WORKING_DIRECTORY "/home/eld/algolab/week3/almost-antenna/__exec_test_dir")
add_test(almost-antenna__SetupFixture "/usr/bin/cmake" "-E" "copy_directory" "/home/eld/algolab/week3/almost-antenna" "/home/eld/algolab/week3/almost-antenna/__exec_test_dir")
set_tests_properties(almost-antenna__SetupFixture PROPERTIES  FIXTURES_SETUP "almost-antenna_" LABELS "almost-antenna_")
add_test(almost-antenna__CleanupFixture "/usr/bin/cmake" "-E" "remove_directory" "/home/eld/algolab/week3/almost-antenna/__exec_test_dir")
set_tests_properties(almost-antenna__CleanupFixture PROPERTIES  FIXTURES_CLEANUP "almost-antenna_" LABELS "almost-antenna_")
