Class=$1
CLASS=$(echo $Class | tr 'a-z' 'A-Z')
folder=ACommand/
HPP=incs/$folder/$Class.hpp
CPP=srcs/$folder/$Class.cpp
cp incs/$folder/SampleHeadercommand.hpp $HPP
cp srcs/$folder/SampleBodycommand.cpp $CPP
sed -i '' "s/NAME/$CLASS/g" $HPP $CPP
sed -i '' "s/Name/$Class/g" $HPP $CPP