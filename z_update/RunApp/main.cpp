#include "spnpwrapper.h"
#include "project.h"
#include <iostream>
#include <fstream>

//https://stackoverflow.com/questions/478898/how-to-execute-a-command-and-get-output-of-command-within-c
int main(int argc, char *argv[])
{
    //if(argc<2) return EXIT_FAILURE;

    /*SPNPWrapper wrap;
    std::string a = "F:/spnp/spnp_win/molloy";
    wrap.work(a);//rgv[1]);*/


    Project* proj = new Project(0);
    for(int i=0; i<2; ++i)
    {
        Net* net = new Net(i);

        for(int j=0; j<10; ++j)
        {
            Place* p = new Place(j*i,"place_"+std::to_string(j), j);
            net->add(p);
            if(j%3==0)
            {
                Transition* t = new Transition((int)j/3, "trans_"+std::to_string(j/3));
                net->add(t);
            }
        }
        proj->addNet(net);
    }


    XMLNode* node = proj->toXML();

    std::string o = node->toString();

    std::ofstream output("file.xml");
    output << o;
    output.close();

    std::ifstream ifs("file.xml");

    XMLNode* node2 = XMLNode::fromString(ifs);

    if(node2->toString() == node->toString())
        printf("ok\n");
    return 0;
}

