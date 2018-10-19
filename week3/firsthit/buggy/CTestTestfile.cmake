# CMake generated Testfile for 
# Source directory: /home/eld/algolab/week3/firsthit/buggy
# Build directory: /home/eld/algolab/week3/firsthit/buggy
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(compilation_of__buggy_solution "/usr/bin/cmake" "--build" "/home/eld/algolab/week3/firsthit/buggy" "--target" "buggy_solution")
set_tests_properties(compilation_of__buggy_solution PROPERTIES  FIXTURES_SETUP "buggy_solution" LABELS "buggy_")
add_test(execution___of__buggy_solution "/home/eld/algolab/week3/firsthit/buggy/buggy_solution")
set_tests_properties(execution___of__buggy_solution PROPERTIES  DEPENDS "compilation_of__buggy_solution" FIXTURES_REQUIRED "buggy_;buggy_solution" LABELS "buggy_" WORKING_DIRECTORY "/home/eld/algolab/week3/firsthit/buggy/__exec_test_dir")
add_test(buggy__SetupFixture "/usr/bin/cmake" "-E" "copy_directory" "/home/eld/algolab/week3/firsthit/buggy" "/home/eld/algolab/week3/firsthit/buggy/__exec_test_dir")
set_tests_properties(buggy__SetupFixture PROPERTIES  FIXTURES_SETUP "buggy_" LABELS "buggy_")
add_test(buggy__CleanupFixture "/usr/bin/cmake" "-E" "remove_directory" "/home/eld/algolab/week3/firsthit/buggy/__exec_test_dir")
set_tests_properties(buggy__CleanupFixture PROPERTIES  FIXTURES_CLEANUP "buggy_" LABELS "buggy_")
