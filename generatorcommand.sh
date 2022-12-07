Class=$1
CLASS=$(echo $Class | tr 'a-z' 'A-Z')
folder=ACommand/
HPP=incs/$folder/$Class.hpp
CPP=srcs/$folder/$Class.cpp
cp incs/$folder/SampleHeadercommand.hpp $HPP
cp srcs/$folder/SampleBodycommand.cpp $CPP
sed -i '' "s/NAME/$CLASS/g" $HPP $CPP
sed -i '' "s/Name/$Class/g" $HPP $CPP

sed -i '' "s/#NEW_CMD_HERE/$Class.cpp \\\#NC/g" Makefile
gsed -i "s/#NC/\n\t\t\t\t\t#NEW_CMD_HERE/g" Makefile
