mkdir ./build
cd ./build
cmake ..
make -j4
#doxygen ../doc/Doxyfile
#./00_algs
#ltrace -e malloc -e free ./allocator > /dev/null
#valgrind --tool=memcheck ./allocator 
valgrind --leak-check=full -v  ./02_xml_parse -p ../xml_files/prel.rpp
#./02_xml_parse -p ../xml_files/sample.fr3
