#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int inf = 1e9 + 1 ;
typedef long long ll;
typedef pair<ll,ll>P;
priority_queue<P,vector<P>,greater<P> >Q;
priority_queue<int, vector<int>, greater<int> >q;
#define sfff(a,b,c)         scanf("%d %d %d",&a,&b,&c)
#define f(x,y,z)            for(int x=y; x<=z; x++)
#define fl(x,y,z)           for(int x=y; x<z; x++)
#define frev(x,y,z)         for(int x=y; x>=z; x--)
#define gcd(x,y)    __gcd(x,y)
#define fast()              ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define mp make_pair
#define pb push_back
#define mx 500005

vector<string>Dataset, Time, Holiday, Location, Wifi, Charging_State, Profile, Mood, Activity, Day;
vector<string> TimeData, HolidayData, LocationData, WifiData, Charging_StateData, ProfileData, MoodData, ActivityData, DayData;
map<string,double>Probability;
map<pair<string, string>, double > Prob;

bool check_subs( string s1, string s2 ) {
    if (s1.find(s2) != std::string::npos) {
        return 1;
    }
    return 0;
}

main() {

    ifstream m;
    m.open("1404107_2018-10-26.csv");

    while(m.good()) {
        string line;
        getline(m, line);
        Dataset.pb(line);
    }
    Day.pb("Sat");Day.pb("Sun");Day.pb("Mon");Day.pb("Tue");Day.pb("Wed");Day.pb("Thu");Day.pb("Fri");

    Time.pb("0.00-1.00"),Time.pb("1.00-2.00"),Time.pb("2.00-3.00"),Time.pb("3.00-4.00"),Time.pb("4.00-5.00"),
    Time.pb("5.00-6.00"),Time.pb("6.00-7.00"),Time.pb("7.00-8.00"),Time.pb("8.00-9.00"),Time.pb("9.00-10.00"),
    Time.pb("10.00-11.00"),Time.pb("11.00-12.00"),Time.pb("12.00-13.00"),Time.pb("13.00-14.00"),Time.pb("14.00-15.00"),
    Time.pb("15.00-16.00"),Time.pb("16.00-17.00"),Time.pb("17.00-18.00"),Time.pb("18.00-19.00"),Time.pb("19.00-20.00"),
    Time.pb("20.00-21.00"),Time.pb("21.00-22.00"),Time.pb("22.00-23.00"),Time.pb("23.00-0.00");

    Holiday.pb("Yes"); Holiday.pb("No");

    Location.pb("Home");Location.pb("Workplace");Location.pb("Canteen");Location.pb("On the way");Location.pb("Playground");

    Charging_State.pb("Charging");Charging_State.pb("Complete");Charging_State.pb("Not Connected");

    Profile.pb("Silent"); Profile.pb("General"); Profile.pb("Aeroplane");Profile.pb("Meeting");Profile.pb("Outdoor"), Profile.pb("Vibration");

    Mood.pb("Happy"); Mood.pb("Sad"); Mood.pb("Normal");

    Activity.pb("Facebook");Activity.pb("Instagram");Activity.pb("Youtube");Activity.pb("Browsing");Activity.pb("Skype");
    Activity.pb("Whatsapp");Activity.pb("Games");Activity.pb("Music");Activity.pb("Movie");Activity.pb("Live Sports");
    Activity.pb("Gmail");Activity.pb("LinkedIn");Activity.pb("Read News");

    Wifi.pb("ON"); Wifi.pb("OFF");

    fl( i, 1, Dataset.size() ) {
        fl( j, 0, Day.size() ) {
            if(check_subs(Dataset[i], Day[j])) {
                DayData.pb(Day[j]);
                break;
            }
        }

        fl( j, 0, Time.size() ) {
            if(check_subs(Dataset[i], Time[j])) {
                TimeData.pb(Time[j]);
                break;
            }
        }

        fl( j, 0, Holiday.size() ) {
            if(check_subs(Dataset[i], Holiday[j])) {
                HolidayData.pb(Holiday[j]);
                break;
            }
        }

        fl( j, 0, Location.size() ) {
            if(check_subs(Dataset[i], Location[j])) {
                LocationData.pb(Location[j]);
                break;
            }
        }

        fl( j, 0, Wifi.size() ) {
            if( check_subs(Dataset[i], Wifi[j])) {
                WifiData.pb(Wifi[j]);
                break;
            }
        }

        fl( j, 0, Charging_State.size() ) {
            if( check_subs(Dataset[i], Charging_State[j])) {
                Charging_StateData.pb(Charging_State[j]);
                break;
            }
        }

        fl( j, 0, Profile.size() ) {
            if( check_subs(Dataset[i], Profile[j])) {
                ProfileData.pb(Profile[j]);
                break;
            }
        }

        fl( j, 0, Mood.size() ) {
            if( check_subs(Dataset[i], Mood[j])) {
                MoodData.pb(Mood[j]);
                break;
            }
        }

        fl( j, 0, Activity.size() ) {
            if( check_subs(Dataset[i], Activity[j])) {
                ActivityData.pb(Activity[j]);
                break;
            }
        }


    }
    //Dataset Complete Hoo Gayaa!!

    fl( i, 0, Activity.size() ) {
        int k = count(ActivityData.begin(), ActivityData.end(), Activity[i]);
        Probability[Activity[i]] = ( (double)k/(double)ActivityData.size() );
    }

    //Probality for Day & Activity
    fl( i, 0, Day.size() ) {
        fl( j, 0, Activity.size() ) {
            int c = 0, coun = count(ActivityData.begin(), ActivityData.end(), Activity[j]);
            fl( k, 0, ActivityData.size()) {
                if( DayData[k] == Day[i] && ActivityData[k] == Activity[j]) {
                    c++;
                }
            }
            if( c == 0 && coun != 0)  { c++; coun = Activity.size()+1; }
            Prob[mp(Day[i], Activity[j])] = (double)c/(double)coun;
        }
    }

    //Probability for Time & Activity
    fl( i, 0, Time.size() ) {
        fl( j, 0, Activity.size() ) {
            int c = 0, coun = count(ActivityData.begin(), ActivityData.end(), Activity[j]);
            fl( k, 0, ActivityData.size()) {
                if( TimeData[k] == Time[i] && ActivityData[k] == Activity[j]) {
                    c++;
                }
            }
            if( c == 0 && coun != 0)  { c++; coun = Activity.size()+1; }
            Prob[mp(Time[i], Activity[j])] = (double)c/(double)coun;
        }
    }

    //Probality for Holiday & Activity
    fl( i, 0, Holiday.size() ) {
        fl( j, 0, Activity.size() ) {
            int c = 0, coun = count(ActivityData.begin(), ActivityData.end(), Activity[j]);
            fl( k, 0, ActivityData.size()) {
                if( HolidayData[k] == Holiday[i] && ActivityData[k] == Activity[j]) {
                    c++;
                }
            }
            if( c == 0 && coun != 0)  { c++; coun = Activity.size()+1; }
            Prob[mp(Holiday[i], Activity[j])] = (double)c/(double)coun;
        }
    }

    //Probality for Location & Activity
    fl( i, 0, Location.size() ) {
        fl( j, 0, Activity.size() ) {
            int c = 0, coun = count(ActivityData.begin(), ActivityData.end(), Activity[j]);
            fl( k, 0, ActivityData.size()) {
                if( LocationData[k] == Location[i] && ActivityData[k] == Activity[j]) {
                    c++;
                }
            }
            if( c == 0 && coun != 0)  { c++; coun = Activity.size()+1; }
            Prob[mp(Location[i], Activity[j])] = (double)c/(double)coun;
        }
    }

    //Probality for Wifi & Activity
    fl( i, 0, Wifi.size() ) {
        fl( j, 0, Activity.size() ) {
            int c = 0, coun = count(ActivityData.begin(), ActivityData.end(), Activity[j]);
            fl( k, 0, ActivityData.size()) {
                if( WifiData[k] == Wifi[i] && ActivityData[k] == Activity[j]) {
                    c++;
                }
            }
            if( c == 0 && coun != 0)  { c++; coun = Activity.size()+1; }
            Prob[mp(Wifi[i], Activity[j])] = (double)c/(double)coun;
        }
    }

    //Probality for Charging_State  & Activity
    fl( i, 0, Charging_State.size() ) {
        fl( j, 0, Activity.size() ) {
            int c = 0, coun = count(ActivityData.begin(), ActivityData.end(), Activity[j]);
            fl( k, 0, ActivityData.size()) {
                if( Charging_StateData[k] == Charging_State[i] && ActivityData[k] == Activity[j]) {
                    c++;
                }
            }//cout<<c<<" "<<coun<<endl;
            if( c == 0 && coun != 0)  { c++; coun = Activity.size()+1; }
            Prob[mp(Charging_State[i], Activity[j])] = (double)c/(double)coun;
        }
    }

    //Probality for Profile & Activity
    fl( i, 0, Profile.size() ) {
        fl( j, 0, Activity.size() ) {
            int c = 0, coun = count(ActivityData.begin(), ActivityData.end(), Activity[j]);
            fl( k, 0, ActivityData.size()) {
                if( ProfileData[k] == Profile[i] && ActivityData[k] == Activity[j]) {
                    c++;
                }
            }
            if( c == 0 && coun != 0)  { c++; coun = Activity.size()+1; }
            Prob[mp(Profile[i], Activity[j])] = (double)c/(double)coun;
        }
    }

    //Probality for Mood & Activity
    fl( i, 0, Mood.size() ) {
        fl( j, 0, Activity.size() ) {
            int c = 0, coun = count(ActivityData.begin(), ActivityData.end(), Activity[j]);
            fl( k, 0, ActivityData.size()) {
                if( MoodData[k] == Mood[i] && ActivityData[k] == Activity[j]) {
                    c++;
                }
            }
            if( c == 0 && coun != 0)  { c++; coun = Activity.size()+1; }
            Prob[mp(Mood[i], Activity[j])] = (double)c/(double)coun;
        }
    }

    cout<<"\t\t\tNaive Bayes Algorithm\n";
    f( i, 1 , 80 ) cout<<"=";
    cout<<"\nEnter Query : ";
    string input[10], inpstr; getline(cin, inpstr);
    fl( i, 0, Day.size() ) {
        if(check_subs(inpstr, Day[i])) {
            input[1] = Day[i];
            break;
        }
    }
    fl( i, 0, Time.size() ) {
        if(check_subs(inpstr, Time[i])) {
            input[2] = Time[i];
            break;
        }
    }
    fl( i, 0, Holiday.size() ) {
        if(check_subs(inpstr, Holiday[i])) {
            input[3] = Holiday[i];
            break;
        }
    }
    fl( i, 0, Location.size() ) {
        if(check_subs(inpstr, Location[i])) {
            input[4] = Location[i];
            break;
        }
    }
    fl( i, 0, Wifi.size() ) {
        if(check_subs(inpstr, Wifi[i])) {
            input[5] = Wifi[i];
            break;
        }
    }
    fl( i, 0, Charging_State.size() ) {
        if(check_subs(inpstr, Charging_State[i])) {
            input[6] = Charging_State[i];
            break;
        }
    }
    fl( i, 0, Profile.size() ) {
        if(check_subs(inpstr, Profile[i])) {
            input[7] = Profile[i];
            break;
        }
    }
    fl( i, 0, Mood.size() ) {
        if(check_subs(inpstr, Mood[i])) {
            input[8] = Mood[i];
            break;
        }
    }


    double prob = 0.0; string ans;
    fl( i, 0, Activity.size() ) {
        double k = 1.0;
        f( j, 1, 8 ) { cout<<Activity[i]<<" "<<input[j]<<endl;
            if(Prob[mp(input[j], Activity[i])] == 0.0)
                continue;
             k = k * Prob[mp(input[j], Activity[i])];
             cout<<k<<endl;
        }
        //cout<<k<<endl;
        if( k >= prob /*&& k != 1*/ ) {
            prob = k;
            ans = Activity[i];
        }

    }


    //cout<<ProfileData.size();
    cout << endl<<"The Result is : "<<ans<<endl;

    //cout<<Charging_State.size()<<" "<<count(Charging_State.begin(), Charging_State.end(), "Not Connected");



}
/*
Fri 8.00-9.00 Yes Home General Happy OFF Charging
Tue 9.00-10.00 No Canteen Normal OFF General Charging
Fri Yes Home 13.00-14.00 OFF Charging Normal General
Sat Yes Home 13.00-14.00 ON Not Connected Normal Silent
*/
