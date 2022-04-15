#include <bits/stdc++.h>
#include<iostream>
#include <string>
#include<cstring>
#include <cstdlib>
#include <algorithm> 
#include <cmath>


using namespace std;

vector<vector<string>>nothingwasthesame 
{

{"a7","b7","c7","d7","e7","f7","g7"},
{"a6","b6","c6","d6","e6","f6","g6"},
{"a5","b5","c5","d5","e5","f5","g5"},
{"a4","b4","c4","d4","e4","f4","g4"},
{"a3","b3","c3","d3","e3","f3","g3"},
{"a2","b2","c2","d2","e2","f2","g2"},
{"a1","b1","c1","d1","e1","f1","g1"}


};

vector<string> split(string str,char separator){

       string temp = "";
       vector<string>holder;
   
      for(int i=0; i<str.length(); i++){
        
         if(str[i] != separator){
            temp += str[i];
        }

          else{
            holder.push_back(temp);
              temp = "";
        }
    }
       
      holder.push_back(temp);

        return holder;
}




vector<vector<string>> set_board(string &fen){

vector<string> v = split(fen, ' ');
vector<string>v2 = split(v[0],'/');


	vector<vector<string>> board;

 for(int i=0;i<7;i++){
		string str = v2[i];
		vector<string> keep;
 			int check;

 			for (int k= 0; k< str.size(); k++)  {

    		check = isdigit(str[k]);
    		if (check){
    	
    			int x=str[k]-48;
    			for(int j=0;j<x;j++){
    				keep.push_back("0");
      					}
      				}
     			else{
     			
     					string s(1,str[k]);
					keep.push_back(s);
						}
  					}
  					board.push_back(keep);			
	
			}
			
			return board;

}

int score_function(string &fen){

	vector<string> temp = split(fen, ' ');

  
  vector<vector<string>> board = set_board(fen);
	
	
	int sumotherpw = 0;
	int sumLw = 0 ;
	
	int sumotherpb = 0;
	int sumLb = 0 ;
	
	int score = 0 ;
      
        
          for(int i=0 ; i < board.size();++i ){
              for(int j = 0; j < board[0].size();++j){


                 if( board[i][j] == "L"){
                 	
                     sumLw = 10000;

                }
                


                if( board[i][j] =="P" ){
                
                      sumotherpw = sumotherpw + 100;
                }
                
             

                if(  board[i][j] == "E"){
                    
                   sumotherpw = sumotherpw + 200;

                }
           
              


             	if(board[i][j] == "Z"){
                
                sumotherpw = sumotherpw + 300;

             	}
           

          // black moves

                 if( board[i][j] == "l"){
                 
                     sumLb = -10000;

                }
                


                if( board[i][j] == "p" ){
                
                      sumotherpb = sumotherpb + 100;
                }
                
             

                if(  board[i][j] == "e"){
                    
                   sumotherpb = sumotherpb + 200;

                }
           
              


             	if(board[i][j] == "z"){
                
                sumotherpb = sumotherpb + 300;

             	}
           

          
     	
     	 }
     	 
      }    
      
      
  
     


          if(temp[1]=="b"){   
          
          
          
         
           
          if( sumLw==0 and sumLb==-10000 ){
           score = 10000 ;
          	
          }
          	
          	
          if(sumLw==10000 and sumLb==0){
          		
          	score = -10000;
          	
          }
          
          
         else{
          
          	int temp2 = sumotherpb - sumotherpw;
               score = temp2;
             //  cout<<score<<endl;
          	
          } 
          
          
          }
          
          
          if(temp[1]=="w"){   
         
           
          if( sumLw==0 and sumLb==-10000 ){
          
          	score = -10000;
          	}
          	
           else if(sumLw==10000 and sumLb==0){
          
          		
          	score = 10000;
          	
          }
          
          
          else{
          	
          	int temp2 = sumotherpw -sumotherpb;
          	score = temp2;
          } 
          
          
          }
         
          
          
          return score;

 }

vector<vector<char>> set_board2(string& fen){

vector<string> v = split(fen, ' ');
vector<string>v2 = split(v[0],'/');


	vector<vector<char>> board;

 for(int i=0;i<7;i++){
		string str = v2[i];
		vector<char> keep;
 			int check;

 			for (int k= 0; k < str.size(); k++)  {

    		check = isdigit(str[k]);
    		if (check){
    	
    			int x=str[k]-48;
    			for(int j=0;j<x;j++){
    				keep.push_back('0');
      					}
      				}
     			else{
     			
					keep.push_back(str[k]);
						}
  					}
  					board.push_back(keep);			
	
			}
			
			return board;

}



string makeMove(string& fen,string& move){

	vector<string> v = split(fen, ' ');
	
	 string OUT=v[1];
	 string p=move;
	int j,i,k,m;
	
	
	if(p[0] == 'a'){
		i =0;
	}
	else if(p[0]=='b'){
		i=1;
	}
	else if(p[0]=='c'){
		i=2;
	}
	else if(p[0]=='d'){
		i=3;
	}
	else if(p[0]=='e'){
		i=4;
	}
	else if(p[0]=='f'){
		i=5;
	}
	else if(p[0]=='g'){
		i=6;
	}
	//column of the first move//
	if(p[1]=='7'){
		j=0;
	}
	else if(p[1]=='6'){
		j=1;
	}
	else if(p[1]=='5'){
		j=2;
	}
	else if(p[1]=='4'){
		j=3;
	}
	else if(p[1]=='3'){
		j=4;
	}
	else if(p[1]=='2'){
		j=5;
	}
	else if(p[1]=='1'){
		j=6;
	}
	//row of the second move//
	if(p[2] == 'a'){
		k =0;
	}
	else if(p[2]=='b'){
		k=1;
	}
	else if(p[2]=='c'){
		k=2;
	}
	else if(p[2]=='d'){
		k=3;
	}
	else if(p[2]=='e'){
		k=4;
	}
	else if(p[2]=='f'){
		k=5;
	}
	else if(p[2]=='g'){
		k=6;
	}
	//column of the second move//
	if(p[3]=='7'){
		m=0;
	}
	else if(p[3]=='6'){
		m=1;
	}
	else if(p[3]=='5'){
		m=2;
	}
	else if(p[3]=='4'){
		m=3;
	}
	else if(p[3]=='3'){
		m=4;
	}
	else if(p[3]=='2'){
		m=5;
	}
	else if(p[3]=='1'){
		m=6;
	}

	
	//input the FEN in the matrix2//
		vector<vector<char>> matrix2 = set_board2(fen);
	
			char HOLD=matrix2[j][i];
			matrix2[j][i]='0';
			

			
			
			if(v[1]=="b"){
				string 	NUM=v[2];
				int num=stoi(NUM)+1;
                
				string STR=to_string(num);
				v[2]=STR;
				v[1]="w";
				
					for(int a=0;a<7;a++){
					
						 
						if(j!=3 && m==3){
							if( matrix2[3][a]=='e' || matrix2[3][a]=='z' || matrix2[3][a]=='p'	||  matrix2[3][a]=='l'){
								matrix2[3][a]='0';
							}
							matrix2[m][k]=HOLD;
						}
						else if(j==3 && m!=3){
							matrix2[m][k]=HOLD;
							if(matrix2[3][a]=='e' || matrix2[3][a]=='z' || matrix2[3][a]=='p'	||  matrix2[3][a]=='l'){
								matrix2[3][a]='0';
							}
						}
                        
						else if(j!=3 && m!=3){
							matrix2[m][k]=HOLD;
							if(matrix2[3][a]=='e' || matrix2[3][a]=='z' || matrix2[3][a]=='p'  ||  matrix2[3][a]=='l'){
								matrix2[3][a]='0';
							}
							
						}
						
						 else if(j==3 && m==3){
						matrix2[m][k]=HOLD;
						if(matrix2[m][k]=='e' || matrix2[m][k]=='z' || matrix2[m][k]=='p'  ||  matrix2[m][k]=='l'){
								matrix2[m][k]='0';
							}
							
						}

					}
				
			}
			else{
				v[1]="b";
					for(int a=0;a<7;a++){
					
						
						if(j!=3 && m==3){
							if( matrix2[3][a]=='E' || matrix2[3][a]=='Z' || matrix2[3][a]=='P' || matrix2[3][a]=='L'){
								matrix2[3][a]='0';
							}
							matrix2[m][k]=HOLD;
						}
						else if(j==3 && m!=3){
							matrix2[m][k]=HOLD;
							if(matrix2[3][a]=='E' || matrix2[3][a]=='Z' || matrix2[3][a]=='P'	|| matrix2[3][a]=='L'){
								matrix2[3][a]='0';
							}
						}
                        
						else if(j!=3 && m!=3){
							
							matrix2[m][k]=HOLD;
							if(matrix2[3][a]=='E' || matrix2[3][a]=='Z' || matrix2[3][a]=='P'	|| matrix2[3][a]=='L'){
								matrix2[3][a]='0';
							}
							
						}
						
						 else if(j==3 && m==3){
						matrix2[m][k]=HOLD;
						if(matrix2[m][k]=='E' || matrix2[m][k]=='Z' || matrix2[m][k]=='P'  ||  matrix2[m][k]=='L'){
								matrix2[m][k]='0';
							}
							
						}
					}
				}
		
 string fen2="";
  for(int i=0;i<7;i++){
	  for(int j=0;j<7;j++){
		  if(matrix2[i][j] == '0'){
			  if(matrix2[i][j+1]=='0' && matrix2[i][j+2]=='0' && matrix2[i][j+3]=='0' && matrix2[i][j+4]=='0' &&matrix2[i][j+5]=='0' && matrix2[i][j+6]=='0'){
				  fen2.push_back('7');
                  j=7;
			  }
			  else if(matrix2[i][j+1]=='0' && matrix2[i][j+2]=='0' && matrix2[i][j+3]=='0' && matrix2[i][j+4]=='0' && matrix2[i][j+5]=='0'){
				  fen2.push_back('6');
                  j=j+5;
			  }
			  else if(matrix2[i][j+1]=='0' && matrix2[i][j+2]=='0' && matrix2[i][j+3]=='0' && matrix2[i][j+4]=='0' ){
				  fen2.push_back('5');
                  j=j+4;
			  }
			  else if(matrix2[i][j+1]=='0' && matrix2[i][j+2]=='0' && matrix2[i][j+3]=='0'){
				  fen2.push_back('4');
                  j=j+3;
			  }
			  else if(matrix2[i][j+1]=='0' && matrix2[i][j+2]=='0'){
				  fen2.push_back('3');
                  j=j+2;
			  }
			  else if(matrix2[i][j+1]=='0'){
				  fen2.push_back('2');
                  j=j+1;
			  }
			  else {
				  fen2.push_back('1');
			  }

		  }
		  else{
			  fen2.push_back(matrix2[i][j]);
		  	}
		
	  	}
		  if(i<=5){
			fen2.push_back('/');
		  }
  }


  string temp = fen2+" "+v[1]+" "+v[2];
  pair<string ,string > temp1;
  
  temp1.first =temp;
 
	
return temp1.first;
}


vector<string> lion_move(string& fen){

vector<string> v = split(fen, ' ');
vector<string>v2 = split(v[0],'/');
vector<vector<char>> matrix2;

 for(int i=0;i<7;i++){
		string str = v2[i];
		vector<char> keep;
 			int check;

 			for (int k= 0; k< str.size(); k++)  {

    		check = isdigit(str[k]);
    		if (check){
    	
    			int x=str[k]-48;
    			for(int j=0;j<x;j++){
    				keep.push_back('0');
      					}
      				}
     			else{
					keep.push_back(str[k]);
						}
  					}
  					matrix2.push_back(keep);
  					
  					
	
			}
			
	string one="";
	vector<string >temp;
	
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			one = one + matrix2[i][j];
		}
		temp.push_back(one);
		one ="";
	}
	
	
	
	for(int i = 0 ; i < temp.size(); ++i){
 	temp[i].erase(5,2);
  	temp[i].erase(temp[i].begin()+0);
   	temp[i].erase(temp[i].begin()+0);
  
	}
		
	vector<vector<string>>board(7, vector<string>(3));
	
	
	for(int i = 0 ; i < board.size(); ++i ){
		
		for(int j = 0 ; j < board[i].size();++j ){
		
			string holder = temp[i];
			
			board[i][j] = holder[j];
			
		}
	
	} 
	
		

  vector<vector<string>>moves
  { 
    {"c7","d7","e7"},
    {"c6","d6","e6"},
    {"c5","d5","e5"},
    {"c4","d4","e4"},
    {"c3","d3","e3"},
    {"c2","d2","e2"},
    {"c1","d1","e1"} 
    
    };

    int b = 0;
    int a = 0;

    for(int i = 0; i < board.size();++i ){

          for(int j = 0;j < board[i].size();++j ){

              if(board[i][j] == "l"){
                  b = i;       
              } 

              if(board[i][j]=="L"){
                  a =i;

              }


          }


    }
  


    vector<string>storewhite;

    for(int i=0;i < board.size();++i){

      for(int j=0; j < board[i].size();++j){
      
      
      if(v[1]=="w"){

          if(board[i][j]=="L"){

           // storewhite.push_back(moves[i][j]);

            if( j-1>=0 and board[i][j-1]!="P" and board[i][j-1]!="E" and board[i][j-1]!="M" and board[i][j-1]!="Z" and board[i][j-1]!="C" and board[i][j-1]!="G"){
              storewhite.push_back( moves[i][j] + moves[i][j-1]);

            }

              if( j+1<3 and board[i][j+1]!="P" and board[i][j+1]!="E" and board[i][j+1]!="M" and board[i][j+1]!="Z" and board[i][j+1]!="C" and board[i][j+1]!="G"){
              storewhite.push_back(  moves[i][j] + moves[i][j+1]);

            }

             if( i-1> 3 and board[i-1][j]!="P" and board[i-1][j]!="E" and board[i-1][j]!="M" and board[i-1][j]!="Z" and board[i-1][j]!="C" and board[i-1][j]!="G"){
              storewhite.push_back( moves[i][j] + moves[i-1][j]);

            }

            if( i+1 <7 and board[i+1][j]!="P" and board[i+1][j]!="E" and board[i+1][j]!="M" and board[i+1][j]!="Z" and board[i+1][j]!="C" and board[i+1][j]!="G"){
              storewhite.push_back(moves[i][j] + moves[i+1][j]);
            }

           if( i-1>3 and j-1>=0 and board[i-1][j-1]!="P" and board[i-1][j-1]!="E" and board[i-1][j-1]!="M" and board[i-1][j-1]!="Z" and board[i-1][j-1]!="C" and board[i-1][j]!="G"){
              storewhite.push_back( moves[i][j] + moves[i-1][j-1]);

           }


             if( i+1<7 and j+1<3 and board[i+1][j+1]!="P" and board[i+1][j+1]!="E" and board[i+1][j+1]!="M" and board[i+1][j+1]!="Z" and board[i+1][j+1]!="C" and board[i+1][j+1]!="G"){
              storewhite.push_back(  moves[i][j] + moves[i+1][j+1]);

            }

            if( i-1>3 and j+1<3 and board[i-1][j+1]!="P" and board[i-1][j+1]!="E" and board[i-1][j+1]!="M" and board[i-1][j+1]!="Z" and board[i-1][j+1]!="C" and board[i-1][j+1]!="G"){
              storewhite.push_back( moves[i][j] + moves[i-1][j+1]);

            }

            if( i+1<7 and j-1>=0 and board[i+1][j-1]!="P" and board[i+1][j-1]!="E" and board[i+1][j-1]!="M" and board[i+1][j-1]!="Z" and board[i+1][j-1]!="C" and board[i+1][j-1]!="G"){
              storewhite.push_back( moves[i][j] + moves[i+1][j-1]);

            }


              vector<string>v;                
              for(int k = i-1; k < board.size();--k){

                  v.push_back(board[k][j]);
                 // cout<<board[k][j]<<endl;
                  if(board[k][j]=="l"){

                    break;
                  }

              }

            
              vector<string> vect2(v);
               v.erase(std::remove(v.begin(), v.end(), "0"), v.end());
                
                if(v.size()==1 and v[0]=="l"){

                    storewhite.push_back( moves[i][j] + moves[b][j]);

                }

                if( board[4][0]=="L" and board[2][2]=="l" and board[3][1]=="0"){
                  storewhite.push_back( moves[i][j] + moves[2][2]);

                 }

               if( board[4][2]=="L" and board[2][0]=="l" and board[3][1]=="0"){
                  storewhite.push_back(moves[i][j] + moves[2][0]);

                }


          
          }
          
          }
          
           

        
      else if(v[1] == "b"){

           if(board[i][j]=="l"){

           // storewhite.push_back(moves[i][j]);

            //move left
            if( j-1 >=0  and board[i][j-1]!="p" and board[i][j-1]!="e" and board[i][j-1]!="m" and board[i][j-1]!="z" and board[i][j-1]!="c" and board[i][j-1]!="g"){
             storewhite.push_back( moves[i][j]+ moves[i][j-1]);

            }

            
             //    move right 
              if( j+1<3 and board[i][j+1]!="p" and board[i][j+1]!="e" and board[i][j+1]!="m" and board[i][j+1]!="z" and board[i][j+1]!="c" and board[i][j+1]!="g"){
              storewhite.push_back( moves[i][j] + moves[i][j+1]);

            }
            

            // move up
             if( i-1 >= 0 and board[i-1][j]!="p" and board[i-1][j]!="e" and board[i-1][j]!="m" and board[i-1][j]!="z" and board[i-1][j]!="c" and board[i-1][j]!="g"){
              storewhite.push_back( moves[i][j] + moves[i-1][j]);

            }

              // move down 
            if( i+1 <3 and board[i+1][j]!="p" and board[i+1][j]!="e" and board[i+1][j]!="m" and board[i+1][j]!="z" and board[i+1][j]!="c" and board[i+1][j]!="g"){
              storewhite.push_back(  moves[i][j] + moves[i+1][j]);
            }
        
            // move north west 
           if( i-1 >= 0 and j-1>=0 and board[i-1][j-1]!="p" and board[i-1][j-1]!="e" and board[i-1][j-1]!="m" and board[i-1][j-1]!="z" and board[i-1][j-1]!="c" and board[i-1][j]!="g"){
              storewhite.push_back( moves[i][j] + moves[i-1][j-1]);

           }

            // move south east
             if( i+1<3 and j+1<3 and board[i+1][j+1]!="p" and board[i+1][j+1]!="e" and board[i+1][j+1]!="m" and board[i+1][j+1]!="z" and board[i+1][j+1]!="c" and board[i+1][j+1]!="g"){
              storewhite.push_back( moves[i][j] + moves[i+1][j+1]);

            }


            // move north east
            if( i-1 >= 0 and j+1<3 and board[i-1][j+1]!="p" and board[i-1][j+1]!="e" and board[i-1][j+1]!="m" and board[i-1][j+1]!="z" and board[i-1][j+1]!="c" and board[i-1][j+1]!="g"){
              storewhite.push_back( moves[i][j] + moves[i-1][j+1]);

            }

          // south west 
            if( i+1<3 and j-1>=0 and board[i+1][j-1]!="p" and board[i+1][j-1]!="e" and board[i+1][j-1]!="m" and board[i+1][j-1]!="z" and board[i+1][j-1]!="c" and board[i+1][j-1]!="g"){
              storewhite.push_back(moves[i][j] + moves[i+1][j-1]);

            }

           

              vector<string>v;
              for(int k = i+1; k < board.size();++k){

                  v.push_back(board[k][j]);
                 // cout<<board[k][j]<<endl;
                  if(board[k][j]=="L"){

                    break;
                  }

              }


            
              vector<string> vect2(v);
               v.erase(std::remove(v.begin(), v.end(), "0"), v.end());  
              // cout<<v[0]<<endl;

                if(v.size()==1 and v[0]=="L"){

                    storewhite.push_back( moves[i][j] + moves[a][j]);

                }




                if( board[4][0]=="L" and board[2][2]=="l" and board[3][1]=="0"){
                   storewhite.push_back( moves[i][j] + moves[4][0]);

                  }

                 if( board[4][2]=="L" and board[2][0]=="l" and board[3][1]=="0"){
                    storewhite.push_back( moves[i][j] + moves[4][2]);

                  }


          
          }

        
	}
          
        
      }
      
      }
      
      sort(storewhite.begin(),storewhite.end() );

          return storewhite;

      
}


vector<string> zebra_moves(string &fen){

vector<string> v = split(fen, ' ');
vector<string>v2 = split(v[0],'/');

	
	vector<vector<string>> board = set_board(fen);



      vector<string>storewhite;

      if(v[1]=="w"){
        
          for(int i=0 ; i < board.size();++i ){
              for(int j = 0; j < board[0].size();++j){

                if(board[i][j]=="Z"){

                 // storewhite.push_back(moves[i][j]);

                 if( j-2 >=0 and i+1 < 7 and board[i+1][j-2]!="P" and board[i+1][j-2]!="E" and board[i+1][j-2]!="M" and board[i+1][j-2]!="L" and board[i+1][j-2]!="C" and board[i+1][j-2]!="G"){
                      storewhite.push_back( nothingwasthesame[i][j] + nothingwasthesame[i+1][j-2]);

                }
                


                if( j+2 < 7 and i+1 < 7 and board[i+1][j+2]!="P" and board[i+1][j+2]!="E" and board[i+1][j+2]!="M" and board[i+1][j+2]!="L" and board[i+1][j+2]!="C" and board[i+1][j+2]!="G"){
                       storewhite.push_back(nothingwasthesame[i][j] + nothingwasthesame[i+1][j+2]);

                }
             

                if( i-1 >= 0 and j+2 < 7 and board[i-1][j+2]!="P" and board[i-1][j+2]!="E" and board[i-1][j+2]!="M" and board[i-1][j+2]!="L" and board[i-1][j+2]!="C" and board[i-1][j+2]!="G"){
                    storewhite.push_back(nothingwasthesame[i][j] + nothingwasthesame[i-1][j+2]);

                }
           

                if( i-1 >= 0 and j-2 >= 0 and board[i-1][j-2]!="P" and board[i-1][j-2]!="E" and board[i-1][j-2]!="M" and board[i-1][j-2]!="L" and board[i-1][j-2]!="C" and board[i-1][j-2]!="G"){
                    storewhite.push_back( nothingwasthesame[i][j] + nothingwasthesame[i-1][j-2]);
               }
            
             

                if( i-2 >=0  and j+1 < 7 and board[i-2][j+1]!="P" and board[i-2][j+1]!="E" and board[i-2][j+1]!="M" and board[i-2][j+1]!="L" and board[i-2][j+1]!="C" and board[i-2][j+1]!="G"){
                    storewhite.push_back(nothingwasthesame[i][j] + nothingwasthesame[i-2][j+1]);

              }
              


             if( i-2 >= 0 and j-1 >= 0 and board[i-2][j-1]!="P" and board[i-2][j-1]!="E" and board[i-2][j-1]!="M" and board[i-2][j-1]!="L" and board[i-2][j-1]!="C" and board[i-2][j-1]!="G"){
                storewhite.push_back(nothingwasthesame[i][j] + nothingwasthesame[i-2][j-1]); 

             }

             if( i+2 < 7 and j+1 < 7 and board[i+2][j+1]!="P" and board[i+2][j+1]!="E" and board[i+2][j+1]!="M" and board[i+2][j+1]!="L" and board[i+2][j+1]!="C" and board[i+2][j+1]!="G"){
                storewhite.push_back(nothingwasthesame[i][j] + nothingwasthesame[i+2][j+1]); 

             }
           


             if( i+2 < 7 and j-1 >= 0 and board[i+2][j-1]!="P" and board[i+2][j-1]!="E" and board[i+2][j-1]!="M" and board[i+2][j-1]!="L" and board[i+2][j-1]!="C" and board[i+2][j-1]!="G"){
                storewhite.push_back( nothingwasthesame[i][j] + nothingwasthesame[i+2][j-1]); 

             }

         
      

          }
          


              }


          }

         
      }


    


    //  black moves 


 if(v[1]=="b"){
        
          for(int i=0 ; i < board.size();++i ){
              for(int j = 0; j < board[0].size();++j){

                if(board[i][j]=="z"){

                 // storewhite.push_back( moves[i][j] + moves[i][j]);

                 if( j-2 >=0 and i+1 < 7 and board[i+1][j-2]!="p" and board[i+1][j-2]!="e" and board[i+1][j-2]!="m" and board[i+1][j-2]!="l" and board[i+1][j-2]!="c" and board[i+1][j-2]!="g" ){
                      storewhite.push_back( nothingwasthesame[i][j] + nothingwasthesame[i+1][j-2]);

                }

                if( j+2 < 7 and i+1 < 7 and board[i+1][j+2]!="p" and board[i+1][j+2]!="e" and board[i+1][j+2]!="m" and board[i+1][j+2]!="l" and board[i+1][j+2]!="c" and board[i+1][j+2]!="g"){
                       storewhite.push_back( nothingwasthesame[i][j] + nothingwasthesame[i+1][j+2]);

                }

                if( i-1 >= 0 and j+2 < 7 and board[i-1][j+2]!="p" and board[i-1][j+2]!="e" and board[i-1][j+2]!="m" and board[i-1][j+2]!="l" and board[i-1][j+2]!="c" and board[i-1][j+2]!="g"){
                    storewhite.push_back( nothingwasthesame[i][j] + nothingwasthesame[i-1][j+2]);

                }

                if( i-1 >= 0 and j-2 >= 0 and board[i-1][j-2]!="p" and board[i-1][j-2]!="e" and board[i-1][j-2]!="m" and board[i-1][j-2]!="l" and board[i-1][j-2]!="c" and board[i-1][j-2]!="g"){
                    storewhite.push_back( nothingwasthesame[i][j] + nothingwasthesame[i-1][j-2]);
               }

                if( i-2 >=0  and j+1 < 7 and board[i-2][j+1]!="p" and board[i-2][j+1]!="e" and board[i-2][j+1]!="m" and board[i-2][j+1]!="l" and board[i-2][j+1]!="c" and board[i-2][j+1]!="g"){
                    storewhite.push_back( nothingwasthesame[i][j] + nothingwasthesame[i-2][j+1]);

              }


             if( i-2 >= 0 and j-1 >= 0 and board[i-2][j-1]!="p" and board[i-2][j-1]!="e" and board[i-2][j-1]!="m" and board[i-2][j-1]!="l" and board[i-2][j-1]!="c" and board[i-2][j-1]!="g"){
                storewhite.push_back(nothingwasthesame[i][j] + nothingwasthesame[i-2][j-1]); 

             }

             if( i+2 < 7 and j+1 < 7 and board[i+2][j+1]!="p" and board[i+2][j+1]!="e" and board[i+2][j+1]!="m" and board[i+2][j+1]!="l" and board[i+2][j+1]!="c" and board[i+2][j+1]!="g"){
                storewhite.push_back(nothingwasthesame[i][j] + nothingwasthesame[i+2][j+1]); 

             }


             if( i+2 < 7 and j-1 >= 0 and board[i+2][j-1]!="p" and board[i+2][j-1]!="e" and board[i+2][j-1]!="m" and board[i+2][j-1]!="l" and board[i+2][j-1]!="c" and board[i+2][j-1]!="g"){
                storewhite.push_back( nothingwasthesame[i][j] + nothingwasthesame[i+2][j-1]); 

             }


          }


              }


          }

         
      }
      sort(storewhite.begin(),storewhite.end());
    
    return storewhite;

} 
vector<string> ElephantMoves(string& fen){

		
vector<string> v = split(fen, ' ');


vector<vector<char>> matrix2  = set_board2(fen);


vector<string> moves;

 if(v[1]=="w"){
 	for(int i=0;i<7;i++){
 			for(int j=0;j<7;j++){
 					if(matrix2[i][j]=='E'){
 							
 								if(i-2>=0){
									 
 									if(matrix2[i-2][j] == 'G' || matrix2[i-2][j] == 'M' || matrix2[i-2][j] == 'E' || matrix2[i-2][j] == 'L' || matrix2[i-2][j] == 'C' || matrix2[i-2][j] == 'Z' || matrix2[i-2][j] == 'P'){
 											int j;
 										}
										 else{
											 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i-2][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 
									 }
 										}
 								if(i-1>=0){
									 
 									 if(matrix2[i-1][j] == 'G' || matrix2[i-1][j] =='M' || matrix2[i-1][j] =='E' || matrix2[i-1][j] =='L' || matrix2[i-1][j] =='C' || matrix2[i-1][j] =='Z' || matrix2[i-1][j] =='P'){
										  	int j;
 										}
										 else{
											  string thanks = nothingwasthesame[i][j] + nothingwasthesame[i-1][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
									 
 										}
 									
 								 if(i+2<=6){
 									if(matrix2[i+2][j] == 'G' ||  matrix2[i+2][j] =='M' || matrix2[i+2][j] =='E' || matrix2[i+2][j] =='L' || matrix2[i+2][j] =='C' || matrix2[i+2][j] =='Z' || matrix2[i+2][j] =='P'){
 										int j;
 										}
										 else{
											 	string thanks = nothingwasthesame[i][j] + nothingwasthesame[i+2][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(i+1<=6){
 									 if(matrix2[i+1][j] == 'G' || matrix2[i+1][j] =='M' || matrix2[i+1][j] =='E' || matrix2[i+1][j] =='L' || matrix2[i+1][j] =='C' || matrix2[i+1][j] =='Z' || matrix2[i+1][j] =='P'){
										  int j;
 										}
										 else{
											 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i+1][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								 if(j-2>=0){
 									if(matrix2[i][j-2] == 'G' || matrix2[i][j-2] =='M' || matrix2[i][j-2] =='E' || matrix2[i][j-2] =='L' || matrix2[i][j-2] =='C' || matrix2[i][j-2] =='Z' || matrix2[i][j-2] =='P'){
 											int j;
 										}
										 else{
											 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i][j-2];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(j-1>=0){
 									 if(matrix2[i][j-1] ==  'G' || matrix2[i][j-1] == 'M' || matrix2[i][j-1] == 'E' || matrix2[i][j-1] == 'L' || matrix2[i][j-1] == 'C' || matrix2[i][j-1] == 'Z' || matrix2[i][j-1] == 'P'){
 										int j;
 										}else{
											 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i][j-1];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								 if(j+1<=6){
 									if(matrix2[i][j+1] == 'G' || matrix2[i][j+1] =='M' || matrix2[i][j+1] =='E' || matrix2[i][j+1] =='L' || matrix2[i][j+1] =='C' || matrix2[i][j+1] =='Z' || matrix2[i][j+1] =='P'){
 										int j;
 										}
										 else{
											 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i][j+1];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(j+2<=6){
 									 if(matrix2[i][j+2] == 'G' || matrix2[i][j+2] =='M' || matrix2[i][j+2] =='E' || matrix2[i][j+2] =='L' || matrix2[i][j+2] =='C' || matrix2[i][j+2] =='Z' || matrix2[i][j+2] =='P'){
 										int j;
 										}
										 else{
											 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i][j+2];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								
 						}
 				}
 		}
 		
 }
 else{
 
 	for(int i=0;i<7;i++){
 			for(int j=0;j<7;j++){
 					if(matrix2[i][j]=='e'){
 							
 								if(i-2>=0){
									 
 									if(matrix2[i-2][j] == 'g' || matrix2[i-2][j] == 'm' || matrix2[i-2][j] == 'e' || matrix2[i-2][j] == 'l' || matrix2[i-2][j] == 'c' || matrix2[i-2][j] == 'z' || matrix2[i-2][j] == 'p'){
 											int j;
 										}
										 else{
											 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i-2][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 
									 }
 										}
 								if(i-1>=0){
									 
 									 if(matrix2[i-1][j] == 'g' || matrix2[i-1][j] =='m' || matrix2[i-1][j] =='e' || matrix2[i-1][j] =='l' || matrix2[i-1][j] =='c' || matrix2[i-1][j] =='z' || matrix2[i-1][j] =='p'){
										  	int j;
 										}
										 else{
											  string thanks =  nothingwasthesame[i][j] + nothingwasthesame[i-1][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
									 
 										}
 									
 								 if(i+2<=6){
 									if(matrix2[i+2][j] == 'g' ||  matrix2[i+2][j] =='m' || matrix2[i+2][j] =='e' || matrix2[i+2][j] =='l' || matrix2[i+2][j] =='c' || matrix2[i+2][j] =='z' || matrix2[i+2][j] =='p'){
 										int j;
 										}
										 else{
											 	string thanks = nothingwasthesame[i][j] + nothingwasthesame[i+2][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(i+1<=6){
 									 if(matrix2[i+1][j] == 'g' || matrix2[i+1][j] =='m' || matrix2[i+1][j] =='e' || matrix2[i+1][j] =='l' || matrix2[i+1][j] =='c' || matrix2[i+1][j] =='z' || matrix2[i+1][j] =='p'){
										  int j;
 										}
										 else{
											 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i+1][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								 if(j-2>=0){
 									if(matrix2[i][j-2] == 'g' || matrix2[i][j-2] =='m' || matrix2[i][j-2] =='e' || matrix2[i][j-2] =='l' || matrix2[i][j-2] =='c' || matrix2[i][j-2] =='z' || matrix2[i][j-2] =='p'){
 											int j;
 										}
										 else{
											 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i][j-2];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(j-1>=0){
 									 if(matrix2[i][j-1] ==  'g' || matrix2[i][j-1] == 'm' || matrix2[i][j-1] == 'e' || matrix2[i][j-1] == 'l' || matrix2[i][j-1] == 'c' || matrix2[i][j-1] == 'z' || matrix2[i][j-1] == 'p'){
 										int j;
 										}else{
											 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i][j-1];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								 if(j+1<=6){
 									if(matrix2[i][j+1] == 'g' || matrix2[i][j+1] =='m' || matrix2[i][j+1] =='e' || matrix2[i][j+1] =='l' || matrix2[i][j+1] =='c' || matrix2[i][j+1] =='z' || matrix2[i][j+1] =='p'){
 										int j;
 										}
										 else{
											 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i][j+1];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(j+2<=6){
 									 if(matrix2[i][j+2] == 'g' || matrix2[i][j+2] =='m' || matrix2[i][j+2] =='e' || matrix2[i][j+2] =='l' || matrix2[i][j+2] =='z' || matrix2[i][j+2] =='z' || matrix2[i][j+2] =='p'){
 										int j;
 										}
										 else{
											 string thanks =  nothingwasthesame[i][j] +  nothingwasthesame[i][j+2];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								
 						}
 				}
 		}
 		
 }
 sort(moves.begin(),moves.end());
 
 return moves;

}

vector<string> PawnMoves(string& fen){

		
vector<string> v = split(fen, ' ');
vector<vector<char>> matrix2 = set_board2(fen);


			

vector<string> moves;

 if(v[1]=="w"){
 	for(int i=0;i<7;i++){
 			for(int j=0;j<7;j++){
 				if(matrix2[i][j]=='P'){
 					if(i<3){
 							if(i==0){
 										//string thanks = matrix[i][j]+matrix[i+1][j];
 										//moves.push_back(thanks);
 										//thanks=" ";
 										
 										
 										 if(matrix2[i+1][j] =='0' ){
											 	 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i+1][j];
 										moves.push_back(thanks);
 										thanks=" ";
										 }
										 
										 if(matrix2[i+1][j] =='0' && matrix2[i+2][j] =='0'  ){
											 	 	 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i+2][j];
 										moves.push_back(thanks);
 										thanks=" ";
 										}
 							
 									}
									 else{
										 if(matrix2[i+1][j] =='0' ){
											 	 string thanks = nothingwasthesame[i][j] +  nothingwasthesame[i+1][j];
 										moves.push_back(thanks);
 										thanks=" ";
										 }
										 
										 if(matrix2[i+1][j] =='0' && matrix2[i+2][j] =='0'  ){
											 	 	 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i+2][j];
 										moves.push_back(thanks);
 										thanks=" ";
										 }
										 
									 }
							 if(i-1>=0){
								 	if(matrix2[i-1][j] == 'G' || matrix2[i-1][j] =='M' || matrix2[i-1][j] =='E' || matrix2[i-1][j] =='L' || matrix2[i-1][j] =='C' || matrix2[i-1][j] =='Z' || matrix2[i-1][j] =='P'){
									 int k;
								 	}
								 	else{
									 	string thanks = nothingwasthesame[i][j] + nothingwasthesame[i-1][j];
 										moves.push_back(thanks);
 										thanks=" ";
									 }
							 	}
							 if(i-1>=0 && j-1>=0){
								 	if(matrix2[i-1][j-1] == 'G' || matrix2[i-1][j-1] =='M' || matrix2[i-1][j-1] =='E' || matrix2[i-1][j-1] =='L' || matrix2[i-1][j-1] =='C' || matrix2[i-1][j-1] =='Z' || matrix2[i-1][j-1] =='P'){
									 	int k;
								 	}
								 	else{
									 string thanks = nothingwasthesame[i][j] +  nothingwasthesame[i-1][j-1];
 										moves.push_back(thanks);
 										thanks=" ";
								 	}
								 
							 	}

							if(i-1>=0 && j+1<=6){
								if(matrix2[i-1][j+1] == 'G' || matrix2[i-1][j+1] =='M' || matrix2[i-1][j+1] =='E' || matrix2[i-1][j+1] =='L' || matrix2[i-1][j+1] =='C' || matrix2[i-1][j+1] =='Z' || matrix2[i-1][j+1] =='P'){
									int k;
								}
								else{
									string thanks = nothingwasthesame[i][j] + nothingwasthesame[i-1][j+1];
 										moves.push_back(thanks);
 										thanks=" ";
								}
							}
							
 					}


				 
				 else{
					 if(i-1>=0){
								 	if(matrix2[i-1][j] == 'G' || matrix2[i-1][j] =='M' || matrix2[i-1][j] =='E' || matrix2[i-1][j] =='L' || matrix2[i-1][j] =='C' || matrix2[i-1][j] =='Z' || matrix2[i-1][j] =='P'){
									 int k;
								 	}
								 	else{
									 	string thanks = nothingwasthesame[i][j] + nothingwasthesame[i-1][j];
 										moves.push_back(thanks);
 										thanks=" ";
									 }
							 	}
							 if(i-1>=0 && j-1>=0){
								 	if(matrix2[i-1][j-1] == 'G' || matrix2[i-1][j-1] =='M' || matrix2[i-1][j-1] =='E' || matrix2[i-1][j-1] =='L' || matrix2[i-1][j-1] =='C' || matrix2[i-1][j-1] =='Z' || matrix2[i-1][j-1] =='P'){
									 	int k;
								 	}
								 	else{
									 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i-1][j-1];
 										moves.push_back(thanks);
 										thanks=" ";
								 	}
								 
							 	}

							if(i-1>=0 && j+1<=6){
								if(matrix2[i-1][j+1] == 'G' || matrix2[i-1][j+1] =='M' || matrix2[i-1][j+1] =='E' || matrix2[i-1][j+1] =='L' || matrix2[i-1][j+1] =='C' || matrix2[i-1][j+1] =='Z' || matrix2[i-1][j+1] =='P'){
									int k;
								}
								else{
									string thanks = nothingwasthesame[i][j] + nothingwasthesame[i-1][j+1];
 										moves.push_back(thanks);
 										thanks=" ";
								}
							}

				 }
				 }

			 }
	 }
 		
 }
 else{
 
 	for(int i=0;i<7;i++){
 			for(int j=0;j<7;j++){
 				
 						if(matrix2[i][j]=='p'){
 					if(i>3){
 							if(i==6){
 										//string thanks = matrix[i][j]+matrix[i-1][j];
 										//moves.push_back(thanks);
 										//thanks=" ";
 										
 										
 										 if(matrix2[i-1][j] =='0' ){
											 	 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i-1][j];
 										moves.push_back(thanks);
 										thanks=" ";
										 }
										 
										 if(matrix2[i-1][j] =='0' && matrix2[i-2][j] =='0'  ){
											 	 	 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i-2][j];
 										moves.push_back(thanks);
 										thanks=" ";
										 }
 							
 									}
									 else{
										 if(matrix2[i-1][j] =='0' ){
											 	 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i-1][j];
 										moves.push_back(thanks);
 										thanks=" ";
										 }
										 
										 if(matrix2[i-1][j] =='0' && matrix2[i-2][j] =='0'  ){
											 	 	 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i-2][j];
 										moves.push_back(thanks);
 										thanks=" ";
										 }
										 
									 }
							 if(i+1<=6){
								 	if(matrix2[i+1][j] == 'g' || matrix2[i+1][j] =='m' || matrix2[i+1][j] =='e' || matrix2[i+1][j] =='l' || matrix2[i+1][j] =='c' || matrix2[i+1][j] =='z' || matrix2[i+1][j] =='p'){
									 int k;
								 	}
								 	else{
									 	string thanks = nothingwasthesame[i][j] + nothingwasthesame[i+1][j];
 										moves.push_back(thanks);
 										thanks=" ";
									 }
							 	}
							 if(i+1<=6 && j-1>=0){
								 	if(matrix2[i+1][j-1] == 'g' || matrix2[i+1][j-1] =='m' || matrix2[i+1][j-1] =='e' || matrix2[i+1][j-1] =='l' || matrix2[i+1][j-1] =='c' || matrix2[i+1][j-1] =='z' || matrix2[i+1][j-1] =='p'){
									 	int k;
								 	}
								 	else{
									 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i+1][j-1];
 										moves.push_back(thanks);
 										thanks=" ";
								 	}
								 
							 	}

							if(i+1<=6 && j+1<=6){
								if(matrix2[i+1][j+1] == 'g' || matrix2[i+1][j+1] =='m' || matrix2[i+1][j+1] =='e' || matrix2[i+1][j+1] =='l' || matrix2[i+1][j+1] =='c' || matrix2[i+1][j+1] =='z' || matrix2[i+1][j+1] =='p'){
									int k;
								}
								else{
									string thanks = nothingwasthesame[i][j] + nothingwasthesame[i+1][j+1];
 										moves.push_back(thanks);
 										thanks=" ";
								}
							}
							
 					}


				 
				 else{
						  if(i+1<=6){
								 	if(matrix2[i+1][j] == 'g' || matrix2[i+1][j] =='m' || matrix2[i+1][j] =='e' || matrix2[i+1][j] =='l' || matrix2[i+1][j] =='c' || matrix2[i+1][j] =='z' || matrix2[i+1][j] =='p'){
									 int k;
								 	}
								 	else{
									 	string thanks = nothingwasthesame[i][j] + nothingwasthesame[i+1][j];
 										moves.push_back(thanks);
 										thanks=" ";
									 }
							 	}
							 if(i+1<=6 && j-1>=0){
								 	if(matrix2[i+1][j-1] == 'g' || matrix2[i+1][j-1] =='m' || matrix2[i+1][j-1] =='e' || matrix2[i+1][j-1] =='l' || matrix2[i+1][j-1] =='c' || matrix2[i+1][j-1] =='z' || matrix2[i+1][j-1] =='p'){
									 	int k;
								 	}
								 	else{
									 string thanks = nothingwasthesame[i][j] + nothingwasthesame[i+1][j-1];
 										moves.push_back(thanks);
 										thanks=" ";
								 	}
								 
							 	}

							if(i+1<=6 && j+1<=6){
								if(matrix2[i+1][j+1] == 'g' || matrix2[i+1][j+1] =='m' || matrix2[i+1][j+1] =='e' || matrix2[i+1][j+1] =='l' || matrix2[i+1][j+1] =='c' || matrix2[i+1][j+1] =='z' || matrix2[i+1][j+1] =='p'){
									int k;
								}
								else{
									string thanks = nothingwasthesame[i][j] + nothingwasthesame[i+1][j+1];
 										moves.push_back(thanks);
 										thanks=" ";
								}
							}

				 }
				 }	
 			}
 							
	}
 		
 }
 sort(moves.begin(),moves.end());


return moves;
}


vector<vector<string>> generateMovesz(string& fen){

	vector<string>thing =  split(fen,' ');
	
	
vector<vector<string>>temp(4);
vector<vector<string>>temp1(4);


 vector<string>movesw;
 vector<string>movesb; 
 

	if(thing[1] == "b"){
		thing[1]="w"; 	
	string tempw  = thing[0] + " " + thing[1] + " " + thing[2];

	
	temp[0] = lion_move(fen);
 	temp[1] = zebra_moves(fen);
 	temp[2] = ElephantMoves(fen);
 	temp[3]  = PawnMoves(fen);
 	
 	temp1[0] = lion_move(tempw);
 	temp1[1] = zebra_moves(tempw);
 	temp1[2] = ElephantMoves(tempw);
 	temp1[3]  = PawnMoves(tempw);
	
	
	
	for(int i = 0; i < 4 ;++i){
 		for(int j = 0; j < temp[i].size();++j){
 		
 			movesb.push_back(temp[i][j]);
 			
 			
 	}
	
	}
	
	
	
	for(int i = 0; i < 4 ;++i){
 		for(int j = 0; j < temp1[i].size();++j){
 			movesw.push_back(temp1[i][j]);
 			
 	
 	}
	
	}


 
 }
 
 
 
	else if(thing[1] == "w"){
		thing[1]="b"; 	
	string tempw  = thing[0] + " " + thing[1] + " " + thing[2];
	
	 temp[0] = lion_move(fen);
 	temp[1] = zebra_moves(fen);
 	temp[2] = ElephantMoves(fen);
 	temp[3]  = PawnMoves(fen);
 	
 	 temp1[0] = lion_move(tempw);
 	temp1[1] = zebra_moves(tempw);
 	temp1[2] = ElephantMoves(tempw);
 	temp1[3]  = PawnMoves(tempw);
	
	
	
	for(int i = 0; i < 4 ;++i){
 		for(int j = 0; j < temp[i].size();++j){
 			movesw.push_back(temp[i][j]);
 			//cout<<temp[i][j]<<endl;
 			
 	
 	}
 	}
	
	
	for(int i = 0; i < 4 ;++i){
 		for(int j = 0; j < temp1[i].size();++j){
 			
 			movesb.push_back(temp1[i][j]);
 	
 	}
	
	
	}

 
 
 }
 
 
 	vector<vector<string>>ls;
 	ls.push_back(movesw);
 	ls.push_back(movesb);
return ls;

}



int attack_score(string& fen){

	vector<vector<string>> ko =  generateMovesz(fen);
	vector<string>temp = split(fen, ' ');
	vector<string> temp2 = split(temp[0],'/');
	
	vector<vector<string>> matrix = set_board(fen);
	
	int attackScorew = 0;
	int attackScoreb = 0;
	int attackScore = 0 ; 	
	

			
			
			
		pair<int, int >index; 	
		
			
	for(int k = 0 ; k < ko[0].size();++k ){
	
		string holder = ko[0][k];
		string s1(1, holder[2]);
		string s2(1, holder[3]);
		string go = s1 + s2;
		
				
			for(int i = 0 ; i < 7;++i){
				for(int j = 0 ;j < 7;++j){
				
					if(nothingwasthesame[i][j] == go){
						index.first = i;
						index.second =j;
						
					}
				
				}
			}

	if( matrix[index.first][index.second] !="0"  ){
		attackScorew = attackScorew + 1;
		//cout<<matrix[index.first][index.second]<<endl;
		
		
		}
		
	 if ( matrix[index.first][index.second] == "l"){
		attackScorew = attackScorew + 10;
	
		}
	
	
	}
	
	pair<int, int >index1; 	
	for(int k = 0 ; k < ko[1].size();++k ){
	
		string holder = ko[1][k];
		string s1(1, holder[2]);
		string s2(1, holder[3]);
		string go = s1 + s2; 
		
		
		
				
			for(int i = 0 ; i < 7;++i){
				for(int j = 0 ;j < 7;++j){
				
					if(nothingwasthesame[i][j] == go){
						index1.first = i;
						index1.second =j;
					
						
					}
				
				}
				
			}
	


	
	

	if( matrix[index1.first][index1.second] != "0"  ){
		attackScoreb = attackScoreb + 1;
		//cout<<matrix[index.first][index.second]<<endl;
		
		}
		
	 if ( matrix[index1.first][index1.second] == "L"){
		attackScoreb = attackScoreb + 10;

		
		}
	
	 }
	 
	 vector<string>animal = split(fen,' ');
	 if(animal[1] == "b"){
		attackScore = attackScoreb - attackScorew;
	
	}
	
	else if(animal[1] == "w"){
	
	attackScore = attackScorew-attackScoreb;
	}
	
	
	
	
	//cout<< attackScore<<endl;

	return attackScore;
		

}



int mobility(vector<vector<string>>tough, string& fen){

	vector<string>temp = split(fen,' ');
	
	int y =0;
	
	if(temp[1] == "b"){
	 y =tough[1].size() - tough[0].size();
	
	}
	
	else if(temp[1] == "w"){
	 y =tough[0].size() - tough[1].size();
	
	}
	
	//cout<<y<<endl;

return y;
}


int material(string fen){


	int score = score_function(fen);
	
	//cout<<score<<endl;
	

return score;

}

int rawScore( string &fen){

	vector<string>temp = split(fen, ' ');
	vector<string> temp2 = split(temp[0],'/');
	
	vector<vector<string>> matrix = set_board(fen);
	
			
			int day = 0;
			int day2 = 0; 
			for(int i = 0; i < matrix.size(); ++i ){
				for(int j = 0; j < matrix.size(); ++j){
			if(matrix[i][j] =="z" or matrix[i][j] =="p" or matrix[i][j] =="e" or matrix[i][j] =="Z" or matrix[i][j] =="E" or matrix[i][j] =="P" ){
					++day;
					
					}
					
					if(matrix[i][j] =="l" or matrix[i][j] =="L"){
					++day2;
					
					}
																		
				
				}
			}
			

	
	int raw = 0 ;
 		
	 if(material(fen) ==10000 || material(fen) == -10000){
	
		return	 material(fen);
	
	}
	
	

	if(material(fen) !=10000 and material(fen) != -10000  ){
	if(day==0 and day2 ==2 ){
		return 0;
	}
	
	   raw = mobility(generateMovesz(fen),fen) + material(fen) + attack_score(fen);
	 
	}
	
	
	
	
 return raw;	
	
}


vector<string> generateMoves(string &fen){


 vector<vector<string>>temp(4);
 vector<string>moves;
 
 temp[0] = lion_move(fen);
 temp[1] = zebra_moves(fen);
 temp[2] = ElephantMoves(fen);
 temp[3]  = PawnMoves(fen);
 
 for(int i = 0; i < 4 ;++i){
 	for(int j = 0; j < temp[i].size();++j){
 		moves.push_back(temp[i][j]);
 		
 	
 	}
 }
 
return moves;

}

bool isGameOver(string &currentState){

  bool whiteL = false ;
  bool blackL =  false ;
  
  for(int i = 0; i < currentState.length(); ++i){
  	
  	if(currentState[i] =='L'){
  		whiteL = true;
  	}
  	
  	if(currentState[i] =='l'){
  		blackL = true;
  	}
  }
  
  if(blackL == true and whiteL == true   ) return false ;
  else return true;  

} 


int alphaBeta(string currentState, int depth,int  alpha,int beta){
	if (isGameOver(currentState) or depth <= 0){
		return rawScore(currentState);
		}
	vector<string>moves = generateMoves(currentState);
	for(int i = 0; i < moves.size(); ++i){
		string nextState = makeMove(currentState, moves[i]);
		int eval = -alphaBeta(nextState, depth - 1, -beta, -alpha);
		if (eval >= beta){
			return beta;
		}
		if( eval > alpha){
			alpha = eval;
			}
	}
return alpha;
}


int main(){


	
	     int N;
     cin >> N;
    cin.ignore(); //NB!
    
    vector<int>we;   
    
   for (int k = 0; k < N; ++k) {

      string fen;
      getline(cin, fen);
      int y = alphaBeta(fen,4,-1000000,1000000);
     
   	  we.push_back(y);
      
      }
      for(int i = 0; i < we.size();++i ){
 
      		cout<<we[i]<<endl;
      }


return 0;

} 
