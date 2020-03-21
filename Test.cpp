#include "PhoneticFinder.hpp"
#include "doctest.h"
using namespace phonetic;
#include <string>
using namespace std;


TEST_CASE("find word mistakes") {
    CHECK(find("Hello","hello") == string("Hello"));
    CHECK(find("jipy","gybi") == string("jipy"));
    CHECK(find("zyse","size") == string("zyse"));
    CHECK(find("muteq","Motek") == string("muteq"));
    CHECK(find("GADOL","gadol")==string("GADOL"));
    CHECK(find("BiG","BIG")==string("BiG"));
    CHECK(find("memory","memuri")==string("memory"));
    CHECK(find("Isolation","izoladyun")==string("Isolation"));
    CHECK(find("Vavo","vavo")==string("Vavo"));
    CHECK(find("SnaKe","snake")==string("SnaKe"));
    CHECK(find("ies","yes")==string("ies"));
    CHECK(find("Out","out")==string("Out"));
}

TEST_CASE("Check long words") {
    CHECK(find("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","AAAAAAAAAAaaaaAAAAAAAAAAaaaAAAAAA") == string("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
    CHECK(find("sofERCALybRAjyLyzdyqEXbyAlyducyuos","Supercalifragilisticexpialidocious") == string("sofERCALybRAjyLyzdyqEXbyAlyducyuos"));
    CHECK(find("davazaouticcc","davasauotikkq")==string("davazaouticcc"));
    CHECK(find("BiG","BIG")==string("BiG"));
    CHECK(find("memory","memuri")==string("memory"));
    CHECK(find("Isolation","izoladyun")==string("Isolation"));
}

TEST_CASE("Checking short words") {
    CHECK(find("v","w") == string("v"));
    CHECK(find("a","A") == string("a"));
    CHECK(find("b","f") == string("b"));
    CHECK(find("b","B") == string("b"));
    CHECK(find("b","p") == string("b"));
    CHECK(find("P","F") == string("P"));
    CHECK(find("i","y") == string("i"));
    CHECK(find("Y","I") == string("Y"));
    CHECK(find("s","z") == string("s"));
    CHECK(find("S","s") == string("S"));
    CHECK(find("q","c") == string("q"));
    CHECK(find("Q","K") == string("Q"));
    CHECK(find("k","c") == string("k"));
    CHECK(find("K","Q") == string("K"));
    CHECK(find("g","j") == string("g"));
    CHECK(find("G","g") == string("G"));
    CHECK(find("G","J") == string("G"));
    CHECK(find("J","G") == string("J"));
}

TEST_CASE("Long sentence short words") {
    CHECK(find("v s d g r n s a","D") == string("d"));
    CHECK(find("v s d g r n s a","t") == string("d"));
    CHECK(find("v i d o r n s a","z") == string("s"));
    CHECK(find("v i d o r n s a","y") == string("i"));
    CHECK(find("v s d g r n s a","A") == string("a"));
    CHECK(find("v s d g r n s a","S") == string("s"));
    CHECK(find("v i d q r n s a","Q") == string("q"));
    CHECK(find("v i d o r n s a","I") == string("i"));
}

TEST_CASE("Test replacement of p , b and f") {
    string text = "fair happy baloon";
    string text2 = "Para BABAIT fUture paffeb";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "pair") == string("fair"));
    CHECK(find(text, "bair") == string("fair"));
    CHECK(find(text, "faloon") == string("baloon"));
    CHECK(find(text2, "para") == string("Para"));
    CHECK(find(text2, "babait") == string("BABAIT"));
    CHECK(find(text2, "pUture") == string("fUture"));
    CHECK(find(text2, "fapbep") == string("paffeb"));
}

TEST_CASE("Test replacement of v , w and g , j") {
    string text = "vamos with veronica when";
    string text2 = "george juice and jum gejeg";
    CHECK(find(text, "wamos") == string("vamos"));
    CHECK(find(text, "vith") == string("with"));
    CHECK(find(text, "weronica") == string("veronica"));
    CHECK(find(text, "vhen") == string("when"));
    CHECK(find(text2, "jeorje") == string("george"));
    CHECK(find(text2, "guice") == string("juice"));
    CHECK(find(text2, "gum") == string("jum"));
    CHECK(find(text2, "jegej") == string("gejeg"));
}

TEST_CASE("Test replacement of s , z and d , t") {
    string text = "suzi goes zadas zooms selfi";
    string text2 = "doubt delled tributed delet trans";
    CHECK(find(text, "zusi") == string("suzi"));
    CHECK(find(text, "goez") == string("goes"));
    CHECK(find(text, "zadaz") == string("zadas"));
    CHECK(find(text, "soomz") == string("zooms"));
    CHECK(find(text, "zelfi") == string("selfi"));
    CHECK(find(text2, "toubd") == string("doubt"));
    CHECK(find(text2, "telled") == string("delled"));
    CHECK(find(text2, "dribuded") == string("tributed"));
    CHECK(find(text2, "deled") == string("delet"));
    CHECK(find(text2, "drans") == string("trans"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "I Dont Want To GO";
    string text2 = "MORE CHECK FOR THIS";
    CHECK(find(text, "i") == string("I"));
    CHECK(find(text, "dont") == string("Dont"));
    CHECK(find(text, "want") == string("Want"));
    CHECK(find(text, "TO") == string("To"));
    CHECK(find(text, "go") == string("GO"));
    CHECK(find(text, "gO") == string("GO"));
    CHECK(find(text, "WANT") == string("Want"));
    CHECK(find(text2, "moRE") == string("MORE"));
    CHECK(find(text2, "Check") == string("CHECK"));
    CHECK(find(text2, "for") == string("FOR"));
    CHECK(find(text2, "thiS") == string("THIS"));
    CHECK(find(text2, "MoRe") == string("MORE"));   
}
