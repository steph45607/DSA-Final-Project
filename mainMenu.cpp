#include <iostream>
using namespace std;

void exitPage(){
    
}

int customMenu(){
    int size;
    cout << "Enter matrix size: ";
    cin >> size;
    // input matrix
    // algoTing(matrix);
    return 3;
    
}

int algoTing(){
    return true;
}

bool MainMenu(){
    int n;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "1. Randomly Generated Matrix and Route" << endl;
    cout << "2. Custom Matrix " << endl;
    cout << "3. More Info" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter an option, bestie <3 : ";
    cin >> n;
    
    if(n == 1){
        cout << "You have chosen option 1." << endl;
        cout << "------------------------" << endl;
    }
    else if(n == 2){
        cout << "You have chosen option 2." << endl;
        cout << "------------------------" << endl;
        customMenu();
    }
    else if(n == 3){
        cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "You have chosen option 3" << endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        cout << "1. Randomly Generated Matrix and Route " << endl;
        cout << "This option will generate a random matrix (duh, it's in the name man). " << endl;
        cout << "You'll be prompted to input the size of the matrix you want, then it will generate a random matrix and" << endl;
        cout << "automatically search the shortest and most optimal routes for it. " << endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        cout << "2. Custom Matrix"<< endl;
        cout << "This custom matrix option will help you to manually input the matrix based on your preferences."<< endl;
        cout << "Input the matrix you want to pathfind," <<endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        cout << "3. More Info" << endl;
        cout << "This option will open the guidebook on the Route-Bot program." << endl;
        cout << "(You're already in this option so idk why you need more info on this but here ya go) "<< endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        cout << "4. Quit... ಠ_ಠ"<< endl;

        return true;
    }else if (n == 4){
        return false;
    }
    else{
        cout << "                    _________________________________________________" << endl;
        cout << "            /|     |                                                 |" << endl;
        cout << "            ||     |   PLEASE ENTER THE RIGHT NUMBER                 |" << endl;
        cout << "       .----|-----,|         PLEASE ENTER THE RIGHT NUMBER           |" << endl;
        cout << "       ||  ||   ==||             PLEASE ENTER THE RIGHT NUMBER       |" << endl;
        cout << "  .-----'--'|   ==||                 PLEASE ENTER THE RIGHT NUMBER   |" << endl;
        cout << "  |)-      ~|     ||_________________________________________________|" << endl;
        cout << "  | ___     |     |____...==..._  >\\______________________________|" << endl;
        cout << " [_/.-.\"---------- //.-.  .-.\\/                   \\ .-.  .-. //" << endl;
        cout << "   ( o )`===\"\"\"\"\"\"\"\"( o )( o )                    `( o )( o )`" << endl;
        cout << "    '-'              '-'  '-'                       '-'  '-'" << endl;
        MainMenu();
    }
}

int main(){
    bool check = true;
    cout <<"--------Welcome to--------" << endl;
    cout <<"╦═╗╔═╗╦ ╦╔╦╗╔═╗  ╔╗ ╔═╗╔╦╗" << endl;
    cout <<"╠╦╝║ ║║ ║ ║ ║╣───╠╩╗║ ║ ║ " << endl;
    cout <<"╩╚═╚═╝╚═╝ ╩ ╚═╝  ╚═╝╚═╝ ╩ " << endl;
    cout <<"Your pathfinding companion" << endl;

    cout <<"          _____" << endl;
    cout <<"         |     |" << endl;
    cout <<"         | | | |" << endl;
    cout <<"         |_____|" << endl;
    cout <<"   ____ ___|_|___ ____" << endl;
    cout <<"  ()___)         ()___)" << endl;
    cout <<"  // /|           |\\ \\\\" << endl; 
    cout <<" // / |           | \\ \\\\" << endl;
    cout <<"(___) |___________| (___)" << endl;
    cout <<"(___)   (_______)   (___)"<< endl;
    cout <<"      |___________| " << endl;
    cout <<"       |||     ||| " << endl;
    cout <<"       |||     ||| " << endl;
    cout <<"       |||     |||  " << endl;
    cout <<"      ()__)   (__()" << endl;
    while(check == true){
        check = MainMenu();
    }
}


//             __________   !SLAM!
//            |  __  __  |
//            | |  ||  | |
//            | |  ||  | |
//            | |__||__| |
//            |  __  __()|
//            | |  ||  | |
//            | |  ||  | |
//            | |  ||  | |
//            | |  ||  | |
//            | |__||__| |
//            |__________|


//                                                            __,-O<            ,-- 
// --.                                  \.          -='            -'    
//    \                                __\\O-                      ,---  
//    --.                                `^                       /      
//       ).          __,-O<    \              __,-O<            ,--      
//  ----'  `.          `\)   __)\O-__           )/          ,--(    ,;:. 
//          _)          /      `^  _)\O<        /          (_      .:;:;.
//        |         |               `^                           :;';.;:'
//        |_        |_        |                                   ';\||' 
// ______/=\\______/=\\_______|                            JML ap    :|  
// '-'-'-[=]/'-'-'-[=]/'-'-'-/'.=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=
// -'-'-'-'-'-'-'-'-'-'-'-'-/   '.                                      |
// '-'-'-'-'-'-'-'-'-'-'-'-/    .-'            .--.--.                |/|
// -'-'-'-'-'-'-'-'-'-'-'-/ _.-'.-:          .; .;|;. ;.            |/|/ 
//        ___       ___   |' _.'\ :|--|--|- .;_;'   ';_;. --|--|--|/|/   
// |]   [|_|_|]   [|_|_|] | |\ | \:|--|--| ; ;'       '; ; -|--|--|/     
// |]   [|_|_|]   [|_|_|] | | \|--'       ;; .--.___.--. ;;              
// _______________________| |.-'          ;-[  O )=( O  ]-;   
//                      |/|               (  `--' | `--'  )       ole mcdonald       
//      ____.-".      |/|/                 \|    (      |/   
//    ;( ,__.)/='   |/|/                    .  .:::::.  .                
//    ; |/  \|    |/|/                       .  '---'  .       
//      \    |  |/|/                         |`.     .'|                 
//       `   `|/|/                  ,-------/|  `...'  |\-------,        
// |--|--|--|/|/                  ,'       | `.       ,' |       `,      
// |--|--|--|/                   /         \  /'.   ,'\  /         \     
//                              ;           |/   \ /   \|           ;    
//                              ;    ;   /  '     |.    '  \  \;    ;    
//                             ;      `-'         |         `-'     MJP  



//                                 ______________________________________
//                                |                                      |
//                     _.---------|.--.                                  |
//                  .-'  `       .'/  ``                                 |
//               .-'           .' |    /|                                |
//            .-'         |   /   `.__//                                 |
//         .-'           _.--/        /                                  |
//        |        _  .-'   /        /                                   |
//        |     ._  \      /     `  /                                    |
//        |        ` .    /     `  /                                     |
//        |         \ \ '/        /                                      |
//        |        - \  /        /|                                      |
//        |        '  .'        / |                                      |
//        |          '         |.'|                                      |
//        |                    |  |                                      |
//        |                    |  |______________________________________|
//        |                    |.'
//        |                    /
//        |                   /
//        |                  /
//        )                 /|
//     .A/`-.              / |
//    AMMMA. `-._         / /
//   AMMMMMMMMA. `-.     / /
//  AMMMMMMMMMMMMA. `.    /
// AMMMMMMMMMMMMMMMMA.`. /
// MMMMMMMMMMMMMMMMMMMA.`.
// MMMMMMMMMMMMMMMMMMMMMA.`.
// MMMMMMMMMMMMMMMMMMMMMMMA.
// MMMMMMMMMMMMMMMMMMMMMMMMMA.
// MMMMMMMMMMMMMMMMMMMMMMMMMMM
// MMMMMMMMMMMMMMMMMMMMMMMMMV'


//                                         /\
//                                         )(
//                                        /{}\
//                                       (    )
//                          ,----------_____....----.--------,
//                 _____.....-----~~~~~             |_______/ `
//                |                                 |      /  |
//                |          O K                    |     /
//                |                                  |   /   /
//                 |                                 | _/   /
//                 |            B Y E                |,'|~~
//                ,|                                ,'  |
//              ,'_|_____________________________:,' /) |.
//              |  \    \                /    /  |  (/  |_. .
//              |   \    \     {}       /    /   |    .' .  .
//           . '|    \    \            / _  /    |    ,   .  .
//          . . |\    \    \          _.( ~-.   /|\ ,' .   . .
//        ` .  -`_-.--.______..._____( ,/  ` \~-.|,' .   .
//         .  `    .     .       .  ,'\. ~-  . , .  .  .   .
//            .  `   .     ,   .      , ~~-.' .  .    .
