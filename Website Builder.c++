#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sys/stat.h>
#include <Windows.h>
#include <direct.h>


using namespace std;

class header { 
private:
   string htmlCode, cssCode;
   int headerNumber;
   string intToString (int num){
      switch (num)
      {
         case 1:
            return "1";
         case 2:
            return "2";
         case 3:
            return "3";
         case 4:
            return "4";
         case 5:
            return "5";

      }
   }
public:
   void chooseHeader (vector <string> pageName){
      cout << "Header 1\n"
              "--------------------------------\n"
              "|             picture          |\n"
              "--------------------------------\n"
              "|  Home  |  Contact  |  About  |\n"
              "--------------------------------\n";
      cout << "Header 2\n"
              "--------------------------------\n"
              "|  Home  |  Contact  |  About  |\n"
              "--------------------------------\n"
              "Please, enter header number: ";
      
      cin >> headerNumber;

      generateCode(pageName);

   }
   void generateCode(vector <string> pageName){ 
      cssCode = "table.headertable { width: 80%; margin-left: auto; margin-right: auto; }";
      cssCode += "td.headertd { border: 1px solid white; color: white; text-align: center; font-size: 20px;} a.headera{ text-decoration: none; color: white;}";
      htmlCode = "<table class=\"headerTable\">";
      if(headerNumber == 1){
         string pictureFileName;
         cout<<"Picture File Name: ";
         cin>>pictureFileName;
         htmlCode += " <tr><td class=\"headertd\"> colspan=\""+ intToString((int)pageName.size()) +"\" <img class=\"headerimg\" src=\"" + pictureFileName;
         htmlCode += "\" /> </td> </tr>";
         cssCode += "img.headerimg { width: 100%; height: auto;}";
      }
      htmlCode += "<tr>";
      htmlCode += "<td class=\"headertd\"> <a class=\"headera\" href=\"index.html\">" + pageName[0] + "</a></td>";
      for (int i=1; i<pageName.size(); ++i)
         htmlCode += "<td class=\"headertd\"> <a class=\"headera\" href=\""+ pageName[i] + ".html\">" + pageName[i] + "</a></td>";
      htmlCode += "</tr></table>";

   }
   string getHtml(){
      return htmlCode;
   }
   string getCss(){
      return cssCode;
   }
};

class footer {
private:
   string htmlCode,cssCode;
public:
   void chooseFooter(string websiteName){
      cout<<"Footer 1:\n"
            "------------------------------------------\n"
            "|   (Website Name) all rights reserved   |\n"
            "------------------------------------------\n"
            "\n\nFooter 2:\n"
            "------------------------------------------\n"
            "|        (Footer background Color)       |\n"
            "|   (Website Name) all rights reserved   |\n"
            "------------------------------------------\n"
            "Enter Footer Number: \n";
      int footerNumber;
      cin>>footerNumber;
      generateCode(footerNumber,websiteName);

   }
   void generateCode(int footerNumber, string websiteName){
      htmlCode = "<br><br><footer><div class=\"footerdiv\">";
      htmlCode += websiteName;
      htmlCode += " all rights reserved</div></footer>";
      cssCode += "footer {margin-left: auto; margin-right: auto;} div.footerdiv {  text-align: center; left: 0; bottom: 0; width: 100%; ";
      if (footerNumber == 2){
         cout<<"Footer Background color: ";
         string footerBackgroundColor;
         cin>>footerBackgroundColor;
         cssCode+="background-color: "+footerBackgroundColor+" ;";

         cout<<"Footer Text Color: ";
         string footerTextColor;
         cin >> footerTextColor;
         cssCode+="color: "+footerTextColor+" ;";
         cssCode+="position: fixed";
      }
      else {
         cout<<"Footer text Color: ";
         string footerTextColor;
         cin>>footerTextColor;
         cssCode+="color: " + footerTextColor + ";";
      }
      cssCode += " }";
   }

   string getHtml (){
      return htmlCode;
   }

   string getCss(){
      return cssCode;
   }

};

// pages classes
class page {
private:
   string htmlCode, cssCode;
public:
   void choosePage (string headerHtml, string footerHtml, string pageName,string backgroundColor){
      cout<<"Page 1\n"
            "-----------------------------------------\n"
            "|   Youtube Video   |   Youtube Video   |\n"
            "-----------------------------------------\n"
            "Page 2\n"
            "-----------------------------------------\n"
            "|   Youtube Video   |       Text        |\n"
            "-----------------------------------------\n"
            "Choose Number: ";
            int pageNumber;
            cin>>pageNumber;
            generateCode(headerHtml,footerHtml,pageName,pageNumber,backgroundColor);

   }
   void generateCode(string headerHtml, string footerHtml, string pageName, int pageNumber, string backgroundColor){
      htmlCode ="<html><head><title>";
      htmlCode += pageName +"</title>";
      
      htmlCode += "<link rel=\"stylesheet\" href=\"css\\header.css\">";
      htmlCode += "<link rel=\"stylesheet\" href=\"css\\footer.css\">";
      cssCode = "body {background-color: "+ backgroundColor +"; } table.pagetable {margin-right: auto; margin-left: auto; width: 80%;} td.pagetd { color: whote; text-align: center; } iframe{width: 100%;}";
      htmlCode += "<style>"+cssCode+"</style></head>";
      htmlCode += "<body><br>"+headerHtml+"<br><br>";
      htmlCode += "<table class=\"pagetable\">";

      cout<<"Enter number of Rows: ";
      int rows;
      cin >> rows;
      for (int r=0;r<rows;++r){
         htmlCode += "<tr><td class=\"pagetd\">";
         string videoLink;
         cout<<"Enter Video Link: ";
         cin>> videoLink;
         htmlCode += "<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/"+videoLink+"?si=OYYszX2RfDgIQkww\" title=\"YouTube video player\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share\" allowfullscreen></iframe>";

         htmlCode += "</td><td class=\"pagetd\">";
         if (pageNumber == 1){
            cout<<"Enter Video Link: ";
            cin>> videoLink;
            htmlCode += "<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/"+videoLink+"?si=OYYszX2RfDgIQkww\" title=\"YouTube video player\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share\" allowfullscreen></iframe>";         
         }
         else if(pageNumber == 2){
            string text;
            cout<<"Enter Text: ";
            getchar();
            getline(cin,text);
            htmlCode += text;
         }
         
         htmlCode += "</td></tr>";
      }
      htmlCode += "</table>"+footerHtml+"</body></html>";
   }
   string getHtml(){
      return htmlCode;
   }
};


class website{
private:
   string websiteName, backgroundColor;
   vector<string> pageName;
public:
   void createWebsite(){
      cout << "Website Name: ";
      cin >> websiteName;
      cout << "Number og Pages: ";
      int numberOfPages;
      cin >> numberOfPages;
      for (int i=0; i<numberOfPages; ++i){
         cout << "page " << (i+1) <<"Name: ";
         string temp;
         cin >> temp;
         pageName.push_back(temp);

      }
      cout << "Background Color: ";
      cin >> backgroundColor;
      header h;
      h.chooseHeader(pageName);

      footer f;
      f.chooseFooter(websiteName);

      CreateDirectory(websiteName.c_str(), NULL );
      string cssFolder = websiteName;
      cssFolder += "//css";
      CreateDirectory(cssFolder.c_str(), NULL );

      string cssFile = cssFolder;
      cssFile += "//header.css";
      ofstream headerCssFile(cssFile);
      headerCssFile << h.getCss();
      headerCssFile.close();

      cssFile = cssFolder;
      cssFile += "//footer.css";
      ofstream footerCssFile(cssFile);
      footerCssFile << f.getCss();
      footerCssFile.close();

      for (int i=0; i<numberOfPages; ++i){
         page p;
         cout<<pageName[i]<<" details"<<endl;
         p.choosePage(h.getHtml(), f.getHtml(), pageName[i], backgroundColor);
         string file = websiteName;
         if (i==0)
            file += "//index.html";
         else
            file += "//"+pageName[i]+".html";
         ofstream pageHtml(file);
         pageHtml << p.getHtml();
         pageHtml.close();
      }
 
   }
};







int main(){
   website w;
   w.createWebsite();
}