Class=$1
CLASS=$(echo $Class | tr 'a-z' 'A-Z')
folder=.
HPP=incs/$folder/$Class.hpp
CPP=srcs/$folder/$Class.cpp
cp incs/SampleHeader.hpp $HPP
cp srcs/SampleBody.cpp $CPP
sed -i '' "s/NAME/$CLASS/g" $HPP $CPP
sed -i '' "s/Name/$Class/g" $HPP $CPP