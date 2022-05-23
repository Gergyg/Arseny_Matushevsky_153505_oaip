#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <string>
#include <QMessageBox>
#include <QDebug>
#include <QString>
//using namespace std;
using ll = long long;
using std::string;
string sum(string a, string b) {
    ll sz = std::min(a.size(), b.size());
    string str;
    ll rem = 0;
    ll c;
    for (ll i = 0; i < sz; i++) {
        c = rem + a[i] + b[i] - '0' - '0';
        str += (char) (c % 2 + '0');
        rem = c / 2;
    }
    for(ll i = sz; i < a.size(); i++) {
        c = rem + a[i] - '0';
        str += (char) (c % 2 + '0');
        rem = c / 2;
    }
    for(ll i = sz; i < b.size(); i++) {
        c = rem + b[i] - '0';
        str += (char) (c % 2 + '0');
        rem = c / 2;
    }
    if(rem) {
        str += '1';
    }
    return str;
}

string x10bin(string& a) {
    string s1 = sum(a, a);
    string s2 = sum(s1, s1);
    string s3 = sum(s2, s2);
    return sum(s1, s3);
}

string x10dig(string& b) {
    return '0'+b;
}

bool check(std::pair<string, string>& s) {
    for (ll i = 0; i < s.first.size(); i++) {
        if(s.first[i] != s.second[i]) {
            return false;
        }
    }
    return true;
}

const ll kkk = 2000;
    std::vector<std::pair<string, string>> ve;
    std::pair<string, string> cur = {"1", "1"};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    while (ve.size() < 10000) {
            ll sz = ve.size();
            ve.push_back(cur);
            if(std::max(sz - kkk, 0ll) > 0) {
                ve.push_back({sum(cur.first, "1"), sum(cur.second, "1")});
            }
            for(ll i = std::max(sz - kkk, 0ll); i < sz; i++) {
                std::pair<string, string> s = {sum(cur.first, ve[i].first), sum(cur.second, ve[i].second)};
                if (check(s)) {
                    ve.push_back(s);
                }
            }

            cur.first = x10dig(cur.first);
            cur.second = x10bin(cur.second);
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::solve(int n){
    string answer="";
    for(int i = ve[n-1].first.size()-1; i>=0; i--){
            answer+=ve[n-1].first[i];
        }
    QMessageBox::information(this, "Answer", QString::fromStdString(answer.c_str()));
}

void MainWindow::on_pushButton_clicked()
{
    int n = ui->spinBox->value();
    if(n==0){
        n = 1;
    }
    solve(n);
}

