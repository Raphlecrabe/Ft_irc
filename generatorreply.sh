Class=$1
CLASS=$(echo $Class | tr 'a-z' 'A-Z')
folder=AReply/
HPP=incs/$folder/$Class.hpp
CPP=srcs/$folder/$Class.cpp
cp incs/$folder/SampleHeaderreply.hpp $HPP
cp srcs/$folder/SampleBodyreply.cpp $CPP
sed -i "s/NAME/$CLASS/g" $HPP $CPP
sed -i "s/Name/$Class/g" $HPP $CPP

Back='\'
sed -i "s/AReply.cpp/AReply.cpp $Back$Back\n\t\t\t\t\t$Class.cpp /g" Makefile