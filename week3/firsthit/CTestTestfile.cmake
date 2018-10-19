# CMake generated Testfile for 
# Source directory: /home/eld/algolab/week3/firsthit
# Build directory: /home/eld/algolab/week3/firsthit
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(compilation_of__firsthit "/usr/bin/cmake" "--build" "/home/eld/algolab/week3/firsthit" "--target" "firsthit")
set_tests_properties(compilation_of__firsthit PROPERTIES  FIXTURES_SETUP "firsthit" LABELS "firsthit_")
add_test(execution___of__firsthit "/home/eld/algolab/week3/firsthit/firsthit")
set_tests_properties(execution___of__firsthit PROPERTIES  DEPENDS "compilation_of__firsthit" FIXTURES_REQUIRED "firsthit_;firsthit" LABELS "firsthit_" WORKING_DIRECTORY "/home/eld/algolab/week3/firsthit/__exec_test_dir")
add_test(firsthit__SetupFixture "/usr/bin/cmake" "-E" "copy_directory" "/home/eld/algolab/week3/firsthit" "/home/eld/algolab/week3/firsthit/__exec_test_dir")
set_tests_properties(firsthit__SetupFixture PROPERTIES  FIXTURES_SETUP "firsthit_" LABELS "firsthit_")
add_test(firsthit__CleanupFixture "/usr/bin/cmake" "-E" "remove_directory" "/home/eld/algolab/week3/firsthit/__exec_test_dir")
set_tests_properties(firsthit__CleanupFixture PROPERTIES  FIXTURES_CLEANUP "firsthit_" LABELS "firsthit_")
