#include <iostream>
#include <cstring>

using namespace std;

class Header
{
    private :
        char m_name[100];
        char m_mode[8];
        char m_uid[8];
        char m_gid[8];
        char m_size[12];
        char m_lastModification[12];
        char m_checksum[8];
        char m_linkType;
        char m_linkName[100];
        char m_null[255];

    public :
        Header()
        {
            for(int i = 0 ; i < 255 ; i ++)
                m_null[i] = '\0';
        }

        Header(char name[], char mode[], char uid[], char gid[],
               char size[], char lastModification[], char checksum[],
               char linkType, char linkName[])
               {
                   setName(name);
                   setMode(mode);
                   setUid(uid);
                   setGid(gid);
                   setSize(size);
                   setLastModification(lastModification);
                   setChecksum(checksum);
                   setLinkType(linkType);
                   setLinkName(linkName);
               }

        char* getName(){return m_name;}
        char* getMode(){return m_mode;}
        char* getUid(){return m_uid;}
        char* getGid(){return m_gid;}
        char* getSize(){return m_size;}
        char* getLastModification(){return m_lastModification;}
        char* getChecksum(){return m_checksum;}
        char getLinkType(){return m_linkType;}
        char* getLinkName(){return m_linkName;}

        void setName(char name[]){strcpy(m_name, name);}
        void setMode(char mode[]){strcpy(m_mode, mode);}
        void setUid(char uid[]){strcpy(m_uid, uid);}
        void setGid(char gid[]){strcpy(m_gid, gid);}
        void setSize(char size[]){strcpy(m_size, size);}
        void setLastModification(char lastModification[]){strcpy(m_lastModification, lastModification);}
        void setChecksum(char checksum[]){strcpy(m_checksum, checksum);}
        void setLinkType(char linkType){m_linkType = linkType;}
        void setLinkName(char linkName[]){strcpy(m_linkName, linkName);}
};

class File
{
    private :
        Header m_header;

    public :
        string getFileType()
        {
            char linkType = m_header.getLinkType();

            switch(linkType)
            {
                case '0' :
                case '\0' :
                        return "file";
                    break;

                case '1' :
                        return "directory";
                    break;
            }
        }

        int getSize()
        {
            char *size = m_header.getSize();


        }
};

int main()
{

    return 0;
}
