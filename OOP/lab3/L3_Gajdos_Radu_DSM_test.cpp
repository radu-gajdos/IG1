#include <iostream>
#include <string>
#include <assert.h>
#include "L3_Gajdos_Radu_DSM.h" // Replace with the name of your header file

using namespace std;
class Test{
public:

    void size(DSM dsm){
        assert(dsm.size()==7);
    };

    void getName(DSM dsm){
        assert(dsm.getName(1)=="Raedern");
    };

    void getNameIndex(DSM dsm){
        assert(dsm.getNameIndex("Lenkrad")==0);
    };

    void setElementName(DSM dsm){
        dsm.setElementName(2,"Motor");
        assert(dsm.getName(2)=="Motor");
    };

    void addLink(DSM& dsm){
        dsm.addLink("Lenkrad","Raedern",4);
        assert(dsm.linkWeight("Lenkrad","Raedern")==4);

        dsm.addLink("Lenkrad","Horn",1);
        assert(dsm.linkWeight("Lenkrad","Horn")==1);

        dsm.addLink("Raedern","Radauflage",1);
        assert(dsm.linkWeight("Raedern","Radauflage")==1);

        dsm.addLink("Motor","Pedale",3);
        assert(dsm.linkWeight("Motor","Pedale")==3);

        dsm.addLink("Motor","Batterie",1);
        assert(dsm.linkWeight("Motor","Batterie")==1);
    };

    void deleteLink(DSM& dsm){
        assert(dsm.linkWeight("Lenkrad","Raedern")==4);
        dsm.deleteLink("Lenkrad","Raedern");
        assert(dsm.linkWeight("Lenkrad","Raedern")==0);

        //wieder die DSM gut bilden indem man dem delete reversiert
        dsm.addLink("Lenkrad","Raedern",4);
    };

    void hasLink(DSM dsm){
        assert(dsm.hasLink("Lenkrad","Raedern")==true);
        assert(dsm.hasLink("Lenkrad","Radauflage")== false);
    };

    void countToLinks(DSM dsm){
        assert(dsm.countToLinks("Lenkrad")==2);
    };

    void countFromLinks(DSM dsm){
        assert(dsm.countFromLinks("Lenkrad")==0);
    };

    void countAllLinks(DSM dsm){
        assert(dsm.countAllLinks()==5);
    };

    void addLinkFaraElemente(DSM& dsm){
        dsm.addLink("a","b",9);
        assert(dsm.size()==9);
        assert(dsm.linkWeight("a","b")==9);
    };

    void addLinkFaraFromElement(DSM& dsm){
        dsm.addLink("c","b",9);
        assert(dsm.size()==10);
        assert(dsm.linkWeight("c","b")==9);
    };

    void addLinkFaraToElement(DSM& dsm){
        dsm.addLink("c","d",9);
        assert(dsm.size()==11);
        assert(dsm.linkWeight("c","d")==9);
    };

    void readFromFile(){
        DSM d(0);
        d.readFromFile(R"(C:\Users\Radu\Desktop\OOP\lab3\in.txt)");
        d.printDSM();
    }

    void writeToFile(){

        DSM dsm(0);
        dsm.addLink("a","b",1);
        dsm.addLink("b","c",1);
        dsm.printDSM();
        dsm.writeToFile(R"(C:\Users\Radu\Desktop\OOP\lab3\out.txt)");
    }

};

int main(){
    string namen[]={"Lenkrad","Raedern","Motor", "Pedale", "Batterie", "Horn", "Radauflage"};
    DSM dsm(namen, 7);
    Test t;


//    t.size(dsm);
//    cout<<"size"<<endl;
//
//    t.getName(dsm);
//    cout<<"getName"<<endl;
//
//    t.getNameIndex(dsm);
//    cout<<"getNameIndex"<<endl;
//
//    t.setElementName(dsm);
//    cout<<"setElementName"<<endl;
//
//    t.addLink(dsm);
//    cout<<"addLink"<<endl;
//
//    t.deleteLink(dsm);
//    cout<<"deleteLink"<<endl;
//
//    t.hasLink(dsm);
//    cout<<"hasLink"<<endl;
//
//    t.countToLinks(dsm);
//    cout<<"countToLinks"<<endl;
//
//    t.countFromLinks(dsm);
//    cout<<"countFromLinks"<<endl;
//
//    t.countAllLinks(dsm);
//    cout<<"countAllLinks"<<endl;
//
//    dsm.printDSM();
//
//    DSM dsm2(namen, 7);
//
//    t.addLinkFaraElemente(dsm2);
//    cout<<"addLinkFaraElemente"<<endl;
//
//    t.addLinkFaraFromElement(dsm2);
//    cout<<"addLinkFaraFromElement"<<endl;
//
//    t.addLinkFaraToElement(dsm2);
//    cout<<"addLinkFaraToElement"<<endl;
//
//    t.readFromFile();

    t.writeToFile();

    cout<<"Testen fertig";

}