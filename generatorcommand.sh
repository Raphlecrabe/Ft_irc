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

sed -i '' "s/#NEW_CMDHPP_HERE/$Class.hpp \\\#NC/g" Makefile
gsed -i "s/#NC/\n\t\t\t\t#NEW_CMDHPP_HERE/g" Makefile

class=$(echo $Class | tr 'A-Z' 'a-z')

sed -i '' "s=//insert_here=insert(\&$class);//NR=g" srcs/CommandCreator.cpp
gsed -i "s=//NR=\n\t//insert_here=g" srcs/CommandCreator.cpp

sed -i '' "s=//cmd_here=$Class	$class;//NR=g" incs/CommandCreator.hpp
gsed -i "s=//NR=\n\t//cmd_here=g" incs/CommandCreator.hpp

sed -i '' "s=//include_here=# include \"$Class.hpp\"//NR=g" incs/ACommand/Includecommand.hpp
gsed -i "s=//NR=\n//include_here=g" incs/ACommand/Includecommand.hpp
