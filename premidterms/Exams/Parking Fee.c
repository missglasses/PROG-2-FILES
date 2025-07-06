#include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    
    typedef struct {
        int hour;
        int minute;
    } Time;
    
    typedef struct {
        Time time_in;
        Time time_out;
        char car_type[20];
    } ParkingInfo;
    
    // Convert 24-hour time to AM/PM format string
    void time_to_ampm(Time t, char *buffer) {
        const char *period = (t.hour < 12) ? "AM" : "PM";
        int display_hour = (t.hour == 0 || t.hour == 12) ? 12 : t.hour % 12;
        sprintf(buffer, "%d:%02d %s", display_hour, t.minute, period);
    }
    
    void get_time_input(const char *prompt, Time *time) {
        printf("%s (HH:MM, 24-hour format): ", prompt);
        while(scanf("%d:%d", &time->hour, &time->minute) != 2 ||
              time->hour < 0 || time->hour > 23 ||
              time->minute < 0 || time->minute > 59) {
            printf("Invalid time format! Please enter in HH:MM format (00:00 to 23:59): ");
            while(getchar() != '\n'); // Clear input buffer
        }
    }
    
    void get_car_type(char *car_type) {
        printf("\nSelect Vehicle Type:\n");
        printf("1 - Motorcycle\n");
        printf("2 - Sedan\n");
        printf("3 - Crossover\n");
        printf("4 - SUV\n");
    
        char input;
        while(1) {
            printf("Enter choice (1-4): ");
            scanf(" %c", &input);
            while(getchar() != '\n'); // Clear input buffer
    
            switch(input) {
                case '1': strcpy(car_type, "Motorcycle"); return;
                case '2': strcpy(car_type, "Sedan"); return;
                case '3': strcpy(car_type, "Crossover"); return;
                case '4': strcpy(car_type, "SUV"); return;
                default: printf("Invalid choice! ");
            }
        }
    }
    
    int time_to_minutes(Time t) {
        return t.hour * 60 + t.minute;
    }
    
    int time_difference(Time start, Time end) {
        return time_to_minutes(end) - time_to_minutes(start);
    }
    
    double calculate_duration_hours(Time start, Time end) {
        return time_difference(start, end) / 60.0;
    }
    
    double calculate_parking_fee(ParkingInfo info) {
        double fee = 0.0;
        // to do code logic here
        double duration = calculate_duration_hours(info.time_in, info.time_out);
    
        
        if(strcmp(info.car_type, "Motorcycle")==0){
            fee = 25.0;
            if (duration >3.0 ){
                fee+= (duration-3.0)*5.0;
            }
        }else if (strcmp(info.car_type,"Sedan")==0){
                 fee = 35.0;
                if (duration >3.0 ){
                fee+= (duration-3.0)*10.0;
            }
        } else if (strcmp(info.car_type,"Crossover")==0){
                 fee = 35.0;
                  if (duration >3.0 ){
                fee+= (duration-3.0)*15.0;
            } 
        }else if (strcmp(info.car_type,"SUV")==0){
                 fee = 35.0;
                  if (duration >3.0 ){
                fee+= (duration-3.0)*20.0;
            }
        }
        
    
        return fee;
    }
    
    void display_parking_info(ParkingInfo info) {
        // to do code logic here
        char entryStr[20],  exitStr[20];
        time_to_ampm(info.time_in, entryStr); 
        time_to_ampm(info.time_out, exitStr); 
        
        printf("\n--- Parking Information ---\n");
        printf("Vehicle Type:  %s\n", info.car_type);
        printf("Entry Time:    %s\n", entryStr);
        printf("Exit Time:     %s\n", exitStr);
        printf("Duration:      %.2f hours\n", calculate_duration_hours(info.time_in, info.time_out));
        printf("Total Fee:     PHP %.2f\n", calculate_parking_fee(info));
    }
    
    int main() {
        printf("=== Parking Fee Calculator ===\n");
    
        ParkingInfo car1;
        get_car_type(car1.car_type);
    
        get_time_input("\nEnter Entry Time", &car1.time_in);
        get_time_input("Enter Exit Time", &car1.time_out);
    
        // Validate that exit time is after entry time
        while(time_difference(car1.time_in, car1.time_out) <= 0) {
            printf("Error: Exit time must be after entry time!\n");
            get_time_input("Enter Exit Time", &car1.time_out);
        }
    
        display_parking_info(car1);
    
        return 0;
    }
