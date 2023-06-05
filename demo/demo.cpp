#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../CJsonObject.hpp"

//int main()
int main(int argc, char* argv[])
{
    std::ifstream fin(argv[1]);
    if (fin.good())
    {
        neb::CJsonObject oJson;
        std::stringstream ssContent;
        ssContent << fin.rdbuf();
        if (oJson.Parse(ssContent.str()))
        {
            std::cout << oJson.ToString() << std::endl;
        }
        else
        {
            std::cerr << "parse json error" << "\n";// << ssContent.str() << std::endl;
        }
        fin.close();
    }
    int iValue;
    double fTimeout;
    std::string strValue;
    neb::CJsonObject oJson("{\"refresh_interval\":60,"
                        "\"test_float\":[18.0, 10.0, 5.0],"
                        "\"test_int\":[135355, -1844674407370955161, -935375],"
                        "\"timeout\":12.5,"
                        "\"dynamic_loading\":["
                            "{"
                                "\"so_path\":\"plugins/User.so\", \"load\":false, \"version\":1,"
                                "\"cmd\":["
                                     "{\"cmd\":2001, \"class\":\"neb::CmdUserLogin\"},"
                                     "{\"cmd\":2003, \"class\":\"neb::CmdUserLogout\"}"
                                "],"
                                "\"module\":["
                                     "{\"path\":\"im/user/login\", \"class\":\"neb::ModuleLogin\"},"
                                     "{\"path\":\"im/user/logout\", \"class\":\"neb::ModuleLogout\"}"
                                "]"
                             "},"
                             "{"
                             "\"so_path\":\"plugins/ChatMsg.so\", \"load\":false, \"version\":1,"
                                 "\"cmd\":["
                                      "{\"cmd\":2001, \"class\":\"neb::CmdChat\"}"
                                 "],"
                             "\"module\":[]"
                             "}"
                        "]"
                    "}");
    std::cout << oJson.ToString() << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;

    neb::CJsonObject pJson("{\"refresh_interval\":60,"
                           "\"test_float\":[18.0, 10.0, 5.0],"
                           "\"test_int\":[135355, -1844674407370955161, -935375],"
                           "\"timeout\":12.5,"
                           "\"dynamic_loading\":["
                           "{"
                           "\"so_path\":\"plugins/User.so\", \"load\":false, \"version\":1,"
                           "\"cmd\":["
                           "{\"cmd\":2001, \"class\":\"neb::CmdUserLogin\"},"
                           "{\"cmd\":2003, \"class\":\"neb::CmdUserLogout\"}"
                           "],"
                           "\"module\":["
                           "{\"path\":\"im/user/login\", \"class\":\"neb::ModuleLogin\"},"
                           "{\"path\":\"im/user/logout\", \"class\":\"neb::ModuleLogout\"}"
                           "]"
                           "},"
                           "{"
                           "\"so_path\":\"plugins/ChatMsg.so\", \"load\":false, \"version\":1,"
                           "\"cmd\":["
                           "{\"cmd\":2001, \"class\":\"neb::CmdChat\"}"
                           "],"
                           "\"module\":[]"
                           "}"
                           "]"
    kJson = "refresh_interval"; //                           "}");
    oJson.Compare(kJson, oJson);  //     bool isSame = oJson.Compare("refresh_interval", oJson);
    bool isSame = oJson.Compare("refresh_interval", pJson);
    std::cout << "isSame:" << isSame << std::endl;

}
