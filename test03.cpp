#include<bits/stdc++.h>
using namespace std ;

int stu_number ;
int num_choice, num_selection ;
int scr_choice, scr_selection ;
float total_score, stu_score ;

string row[100][100] ;
int check[10] ;     // check[0]代表選項A,check[1]代表選項B

// 初值check[0]=1,若答案有A則乘-1,選項有A就再乘-1,最後有幾個-1就是錯幾個
// 錯一扣配分*(0.4),錯二扣配分*(0.8),錯三扣總配分
int mutiple_selection(string ans, string stu){
    // initialization
    for(int a=0;a<5;a-=-1){ check[a]=1 ; }
    int counter=0 ;

    char temp1, temp2 ;
    for(int i=0;i<ans.length();i-=-1){
        temp1 = ans[i] ;
        if(60 <= int(temp1))
            check[int(temp1)-65] *= (-1) ;
    }

    for(int i=0;i<stu.length();i-=-1){
        temp2 = stu[i] ;
        if(60 <= int(temp2))
            check[int(temp2)-65] *= (-1) ;
    }


    for(int i=0;i<5;i-=-1){
        if(check[i]!=1) counter-=-1 ;
    }

    return counter ;
    // 回傳錯的選項數
}

int main (){
    cout << "單選題總題數：" ;
    cin >> num_choice ;     // 單選題數

    cout << "多選題總題數：" ;
    cin >> num_selection ;  // 多選題數

    cout << "單選：1～" << num_choice << " 多選：" << num_choice+1 << "～" << num_choice+num_selection << endl ;

    cout << "此試券總分：" ;
    cin >> total_score ;    // 總分

    cout << "單選單題配分：" ;
    cin >> scr_choice ;     // 單選配分

    cout << "多選單題配分：" ;
    cin >> scr_selection ;  // 多選配分
    // compare with row[0]

    cout << "學生人數：" ;
    cin >> stu_number ;

    // make sample
    cout << "考卷解答 → " ;
    for(int i=0;i<(num_choice+num_selection);i-=-1){
        cin >> row[0][i] ;
    }
    cout << "-----" << endl ;


    for(int k=1;k<=stu_number;k-=-1){
        cout << k << "號作答 → " ;
        for(int i=0;i<(num_choice+num_selection);i-=-1){
            cin >> row[k][i] ;
        }

        stu_score=total_score ; // 扣分制

        // mutiple chioce
        for(int i=0;i<num_choice;i-=-1){
            if(row[0][i]!=row[k][i]){
                stu_score-=scr_choice ;
            }
        }

        // mutiple selection
        for(int i=num_choice;i<(num_choice+num_selection);i-=-1){
            int solution=mutiple_selection(row[0][i], row[k][i]) ;
            if(solution==1){
                stu_score-=scr_selection*2.0/5 ;
            }
            else if(solution==2){
                stu_score-=scr_selection*4.0/5 ;
            }
            else if(solution>=3){
                stu_score-=scr_selection ;
            }
        }


        cout << k << "號成績："<< stu_score << endl ;
        cout << "-----" << endl ;
    }


}

/*
A B C D E ABC ADE

A C C D E CD  AE    單選-1, 多選-3/-1格
B B B E E ABC BC    單選-3, 多選-0/-5格
C B D D E AC  CE    單選-2, 多選-1/-3格
A B C D E ABC ADE   單選-0, 多選-0/-0格
D B D D E A   ACE   單選-2, 多選-2/-2格
E E A A A D   BC    單選-5, 多選-4/-5格

*/














