#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidget>
#include <QFileDialog>
#include <QTextStream>
#include <QTableWidgetItem>
#include <string>
#include <fstream>
#include <QDebug>
#include <iostream>
#include <stack>
#include <regex>
#include <map>
#include <vector>

QString global_file_name;
//using namespace std;
using std::vector;
using std::map;
using string = spd::String;
using std::stack;
using std::regex;
using std::cout;
using std::to_string;
using std::cmatch;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



struct Data {
    int posX, posY;
    string sData;
};
string helpData;
vector < string > local;
vector < string > varTypes = {"int", "long long", "long int","long double","char","float","bool","double","long","short","size_t", "void", "string"};
map < string, vector < string > > varMap;
vector < Data > vec;
string allData;
bool isBracket(char c) {
    return (c == '{') || (c == '[') || (c == '(') || (c == '}') || (c == ']') || (c == ')');
}
bool check_isCl(string s) {
    for (int i = s.size() - 2; i >= 0; i--) {
        if (s[i] == ' ') {
            continue;
        }
        else {
            if (s[i] == '=') {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
    return 0;
}
bool checkBal(string s) {
    stack<char> Stack;
    bool isStr = 0, isChar = 0, isCom1 = 0, isCom2 = 0;
    int y = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '\n') {
            isCom1 = 0;
            y++;
            continue;
        }
        if (s[i] == '"' && !isCom1 && !isCom2) {
            if (!isChar) {
                isStr ^= 1;
            }
        }
        if (s[i] == '\'' && (s[i - 1] != '\\' || (s[i - 1] == '\\' && s[i - 2] == '\\')) && !isCom1 && !isCom2) {
            if (!isStr) {

                isChar ^= 1;
            }
        }
        if (i + 1 < s.size() && !isChar && !isStr && !isCom1) {
            if (s[i] == '/' && s[i + 1] == '/') {
                isCom1 = 1;
            }
            if (s[i] == '/' && s[i + 1] == '*') {
                isCom2 = 1;
            }
            if (s[i] == '*' && s[i + 1] == '/') {
                isCom2 = 0;
            }
        }
        if (!isBracket(s[i]) || isChar || isStr || isCom1 || isCom2) {
            continue;
        }
    //	cout << y << ' ' << s[i] << '\n';
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            Stack.push(s[i]);
        }
        else {
            if (abs(int(Stack.top() - s[i])) <= 2) {
                Stack.pop();
            }
            else {
                return 0;
            }
        }
    }
    return 1;
}
void divideStr(string s) {
    string tmp;
    int x = 1, y = 0;
    bool isStr = 0, isChar = 0;
    bool isCom1 = 0, isCom2 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '\n') {
            isCom1 = 0;
            x++;
            y = 1;
            continue;
        }
        y++;
        if (s[i] == '"' && isCom1 == 0 && isCom2 == 0) {
            if (!isChar) {
                isStr ^= 1;
            }
        }
        if (s[i] == '\'' && (s[i - 1] != '\\' || (s[i - 1] == '\\' && s[i - 2] == '\\')) && !isCom1 && !isCom2) {
            if (!isStr) {
                isChar ^= 1;
            }
        }
        if (i + 1 < s.size() && !isChar && !isStr && !isCom1) {
            if (s[i] == '/' && s[i + 1] == '/') {
                isCom1 = 1;
            }
            if (s[i] == '/' && s[i + 1] == '*') {
                isCom2 = 1;
            }
            if (s[i] == '*' && s[i + 1] == '/') {
                isCom2 = 0;
            }
        }
        if (s[i] != '\t' && !isStr && !isChar && !isCom1 && !isCom2) {
            helpData += s[i];

            tmp += s[i];
        }
        if (!isStr && !isChar && !isCom1 && !isCom2) {
            if (s[i] == ';' || (s[i] == '{' && !check_isCl(tmp))) {

                Data ne = { x, y, tmp };
                if (tmp.size() != 1) {
                    vec.push_back(ne);
                }
                tmp = "";
            }
        }
    }
}
string types = "int|long long|long int|long double|char|float|bool|double|long|short|size_t|void";
bool type_check(string s) {
    for (int i = 0; i < varTypes.size(); i++) {
        if (s == varTypes[i]) {
            return 1;
        }
    }
    return 0;
}
bool is_num(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return 0;
        }
    }
    return 1;
}
void MainWindow::findVar() {
    int vloz = 0;
    string addVloz = " global ";
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].sData.size(); j++) {
            if (vec[i].sData[j] == '{') {
                vloz++;
            }
            if (vec[i].sData[j] == '}') {
                vloz--;
            }
        }
        if (vloz) {
            addVloz = " local ";
        }
        else {
            addVloz = " global ";
        }
        string pp = "(";
        pp +=types;
        pp +=")\\s+\\w+\\s*[\\S|\\s]*[;]{1,1}";
        //regex regular("(" + types + ")" + "\\s+\\w+\\s*[\\S|\\s]*[;]{1,1}");
        regex regular(pp.c_str());
        std::cmatch result;
        if (regex_search(vec[i].sData.c_str(), result, regular)) {
            vector < string > ne;
            bool isOp = 0;
            string vs = vec[i].sData, tmp = "";
            for (int j = 0; j < vs.size(); j++) {
                if (type_check(tmp)) {
                    tmp = "";
                }
                if (vs[j] == '{') {
                    isOp = 1;
                }
                if (vs[j] == '}') {
                    isOp = 0;
                }
                if (vs[j] == ';' || vs[j] == ',') {
                    if (isOp) {
                        continue;
                    }
                    if (!type_check(tmp) && tmp.size()) {
                        ne.push_back(tmp);
                    }
                    tmp = "";
                }
                else {
                    tmp += vs[j];
                }
            }
            for (int j = 0; j < ne.size(); j++) {
                regular = "(\\s*\\w+\\s*(\\s*\=\\s*[0-9]{1,100})?)";
                if (regex_match(ne[j].c_str(), result, regular)) {
                    tmp = "";
                    vector < string > newVar;
                    for (int z = 0; z < ne[j].size(); z++) {
                        if (ne[j][z] == ' ' || ne[j][z] == '=') {
                            if (tmp.size()) {
                                newVar.push_back(tmp);
                            }
                            tmp = "";
                        }
                        else {
                            tmp += ne[j][z];
                        }
                    }
                    if (tmp.size()) {
                        newVar.push_back(tmp);
                    }
                    if (newVar.size() == 2) {
                        string t = "New";
                        t +=addVloz;
                        t +="var ";
                        t += newVar[0];
                        t += " = ";
                        t += newVar[1];
                        t += " at line ";
                        QString R = QString::fromLatin1(t.c_str());
                        R = R + QString::number(vec[i].posX);
                        ui->listWidget->addItem(R);
                        //std::cout << "New" + addVloz.c_str() + "var " + newVar[0] + " = " + newVar[1] + " at line " + std::to_string(vec[i].posX) << endl;
                    }
                    else {
                        string t = "New";
                        t +=addVloz;
                        t +="var ";
                        t += newVar[0];
                        t += " at line ";
                        QString R = QString::fromLatin1(t.c_str());
                        R = R + QString::number(vec[i].posX);
                        ui->listWidget->addItem(R);
                        //std::cout << "New" + addVloz + "var " + newVar[0] + " at line " + std::to_string(vec[i].posX) << endl;
                    }
                }

                regular = "(\\s*\\w\\s*\\[\\d{0,100}\\])(\\s*=\\s*\\{(\\s*\\d+\\s*)*\\})?";
                if (regex_match(ne[j].c_str(), result, regular)) {
                    tmp = "";
                    vector < string > newVar;
                    for (int z = 0; z < ne[j].size(); z++) {
                        /*if (ne[j][z] == ' ' || ne[j][z] == '=') {
                            if (tmp.size()) {
                                newVar.push_back(tmp);
                            }
                            tmp = "";
                        }
                        else {*/
                            tmp += ne[j][z];
                    //	}
                    }
                    if (tmp.size()) {
                        newVar.push_back(tmp);
                    }
                    if (newVar.size() == 2) {
                        string t = "New";
                        t +=addVloz;
                        t +="arr ";
                        t += newVar[0];
                        t += " = ";
                        t += newVar[1];
                        t += " at line ";
                        QString R = QString::fromLatin1(t.c_str());
                        R = R + QString::number(vec[i].posX);
                        ui->listWidget->addItem(R);
                        //cout << "New" + addVloz + "arr " + newVar[0] + "=" + newVar[1] + " at line " + to_string(vec[i].posX) << endl;
                    }
                    else {
                        //cout << "New" + addVloz + "arr " + newVar[0] + " at line " + to_string(vec[i].posX) << endl;
                        string t = "New";
                        t +=addVloz;
                        t +="arr ";
                        t += newVar[0];
                        t += " at line ";
                        QString R = QString::fromLatin1(t.c_str());
                        R = R + QString::number(vec[i].posX);
                        ui->listWidget->addItem(R);
                    }
                }
            }
            vec[i].sData = "";
        }
    }
}
void MainWindow::findChange() {
    for (int i = 0; i < vec.size(); i++) {
        regex regular("\\s*\\w+\\s*(\\[[\\d]{1,100}\\])?=\\s*\\d+;");
        cmatch result;
        if (regex_search(vec[i].sData.c_str(), result, regular)) {
            string s1 = "", s2 = "";
            bool isW = 0;
            for (int j = 0; j < vec[i].sData.size(); j++) {
                if (vec[i].sData[j] == '=') {
                    isW = 1;
                    continue;
                }
                if (!isW) {
                    s1 += vec[i].sData[j];
                }
                else {
                    s2 += vec[i].sData[j];
                }
            }
            string t = "at line ";
            QString R = QString::fromLatin1(t.c_str());
            R += QString::number(vec[i].posX);
            t = " ";
            t += s1;
            t+="has changed to";
            t +=s2;
            R += QString::fromLatin1(t.c_str());
            ui->listWidget->addItem(R);
            //cout << "at line " + to_string(vec[i].posX) + " " + s1 + "has changed to" << s2 << endl;
        }
    }
}
void MainWindow::findClass() {
    for (int i = 0; i < vec.size(); i++) {
        regex regular("(class|struct)\\s*\\w+\\s*\\{");
        cmatch result;
        string t;
        if (regex_search(vec[i].sData.c_str(), result, regular)) {
            for (int j = 0; j < vec[i].sData.size(); j++) {
                if (vec[i].sData[j] != '}') {
                    //cout << vec[i].sData[j];
                    t += vec[i].sData[j];
                }
            }
            ui->listWidget->addItem(QString::fromLatin1(t.c_str()));
            //cout << endl;
        }
    }
}
map < string, int > funcMap;
void findFunc() {
    for (int i = 0; i < vec.size(); i++) {
        string pp = "(";
        pp+=types;
        pp+=")\\s+\\w+\\s*\\((\\s*(type)\\s*\\w+(\\s*=\\d+\\s*)?\\s*[,|\\)]{1,1})*";
        //regex regular("(" + types + ")" + "\\s+\\w+\\s*\\((\\s*(type)\\s*\\w+(\\s*=\\d+\\s*)?\\s*[,|\\)]{1,1})*");
        regex regular(pp.c_str());
        cmatch result;
        if (regex_search(vec[i].sData.c_str(), result, regular)) {
            string tmp = "";
            bool ch = 0;
            for (int j = 0; j < vec[i].sData.size(); j++) {
                if (vec[i].sData[j] == ' ' || vec[i].sData[j] == '(') {
                    if (!ch) {
                        ch = 1;
                        tmp = "";
                        continue;
                    }
                    else {
                        funcMap[tmp]++;
                        break;
                    }
                }
                tmp += vec[i].sData[j];
            }
        }
    }
}
void MainWindow::coutOverloadedFunc() {
    for (auto& item : funcMap) {
        if (item.second > 1) {
            string t = "func ";
            string fir = item.first;
            t+=fir;
            t+=" has Overloaded ";
            QString R = QString::fromLatin1(t.c_str());
            R += QString::number(item.second);
            ui->listWidget->addItem(R);
            //cout << "func " + item.first + " has Overloaded " + to_string(item.second) + " times" << endl;
        }
    }
}
void MainWindow::findIfDeep() {
    int tekDeep = 0;
    bool isIf = 0;
    stack < std::pair < char, bool > > bal;
    for (int i = 0; i < helpData.size(); i++) {
        if (i + 2 < helpData.size()) {
            if (helpData[i] == 'i' && helpData[i + 1] == 'f' && helpData[i + 2] == ' ') {
                string tmp = "";
                while (helpData[i] != '{') {
                    tmp += helpData[i];
                    i++;
                }
                bal.push({ '{', 1 });
                tekDeep++;
                string t = tmp;
                t+=' ';
                t+="deep = ";
                QString R = QString::fromLatin1(t.c_str());
                R += QString::number(tekDeep);
                ui->listWidget->addItem(R);
                //cout << tmp << ' ' << "deep = " << tekDeep << endl;
                continue;
            }
        }
        if (!isBracket(helpData[i])) {
            continue;
        }
        if (helpData[i] == '}' || helpData[i] == ')' || helpData[i] == ']') {
            tekDeep -= bal.top().second;
            bal.pop();
        }
        else {
            bal.push({ helpData[i], 0 });
        }
    }
}

void MainWindow::findError() {
    for (int i = 0; i < vec.size(); i++) {
        regex regular("\\s*((while|if)\\s?\\((true|false)\\);?)$");
        cmatch result;
        string t;
        if (regex_search(vec[i].sData.c_str(), result, regular)) {
            for (int j = 0; j < vec[i].sData.size(); j++) {
                if (vec[i].sData[j] != '}') {
                    //cout << vec[i].sData[j];
                    t += vec[i].sData[j];
                }
            }
            QString R = "Logical error ";
            R+=QString::fromLatin1(t.c_str());
            ui->listWidget->addItem(R);
            //cout << endl;
        }
    }
}

void MainWindow::on_actionOpen_triggered()
{

    global_file_name = QFileDialog::getOpenFileName(this, "Выберите", QDir::currentPath(), "*.cpp");
    QMessageBox::information(this, "debug", global_file_name);
    if(global_file_name==nullptr){
        return;
    }
    QByteArray temp = global_file_name.toLocal8Bit();
    const char *filePath = temp.data();
    std::ifstream file(filePath);
    allData = "";
    funcMap.clear();
    varMap.clear();
    vec.clear();
    helpData = "";
    local.clear();
    ui->listWidget->clear();


    while (!file.eof()) {
            allData += file.get();
    }



        file.close();
        if (!checkBal(allData)) {
            QMessageBox::information(this, "debug", "Bracket balance error");
            return;
        }


        divideStr(allData);

        findVar();
        findChange();
        findClass();
        findFunc();
        coutOverloadedFunc();
        findIfDeep();
        global_file_name = nullptr;
}

