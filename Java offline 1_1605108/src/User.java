import java.io.*;
import java.util.Scanner;

public class User {
    public static Build SampleCar = new Build();
    private static Cars car;

    public static void main(String[] args) {
        Scanner choice = new Scanner(System.in);
        while(true) {
            System.out.println("Enter your choice :");
            System.out.println("1.Search Cars");
            System.out.println("2.Add Car");
            System.out.println("3.Delete Car");
            System.out.println("4.Exit System");
            int c = choice.nextInt();
            if(c==4)
            {
                break;
            }

            else if(c==1)
            {
                Search();
            }

           else if(c==2)
            {
                Cars cr = add();
                SampleCar.carList.add(cr);
            }
           else if(c==3)
            {
                delete();
            }

            else
            {
                System.out.println("Please Give A Valid Input(1-4)");
            }
        }
        writeFile(SampleCar);
    }
    public static void Search()
    {
        Scanner c1 = new Scanner(System.in);
        Scanner c2 = new Scanner(System.in);
        while(true) {
            System.out.println("How To Search Cars : ");
            System.out.println("1.By Registration Number");
            System.out.println("2.By Car Make and Car Model");
            System.out.println("3.Back to Main Menu");
            int c = c1.nextInt();

            if (c == 1)
            {
                System.out.println("Enter the Registration Number :");
                String str = c2.nextLine();
                searchByReg(str, true);
            }
            else if (c == 2)
            {
                System.out.println("Enter the Car Make :");
                String str1 = c2.nextLine();
                System.out.println("Enter the Car Model :");
                String str2 = c2.nextLine();
                searchBycarmake(str1, str2);
            }
            else if (c == 3)
            {
                break;
            }
            else
            {
                System.out.println("Please Give A Valid Input(1-3)");
                break;
            }
        }
    }
    public static void searchByReg(String str,boolean t)
    {
        int searchindex = -1;
        for (int i = 0; i < SampleCar.carList.size(); i++) {
            if (str.equalsIgnoreCase(SampleCar.carList.get(i).getRegname())) {
                searchindex = i;
            }
        }
        if (searchindex == -1) {
            System.out.println("Not found in the car list");
        }
        else{
            if(t)
            {
                Display(SampleCar.carList.get(searchindex));
            }
            else{
                Scanner input = new Scanner(System.in);
                Display(SampleCar.carList.get(searchindex));
                System.out.println("Do you want to delete this car?");
                System.out.println("If you want to,press 1 ; else press 0");
                int choice = input.nextInt();
                if(choice == 1){
                    SampleCar.carList.remove(SampleCar.carList.get(searchindex));
                }
            }
        }
    }



    public static void searchBycarmake(String str1,String str2)
    {
        int searchindex = -1;
        if(str2.equalsIgnoreCase("any")) {
            for (int i = 0; i < SampleCar.carList.size(); i++) {
                if (str1.equalsIgnoreCase(SampleCar.carList.get(i).getCarmake())) {
                    Display(SampleCar.carList.get(i));
                    searchindex = i;
                }
            }
        }
        else if(!(str2.equalsIgnoreCase("any"))){
            for (int i = 0; i < SampleCar.carList.size(); i++) {
                if ((str1.equalsIgnoreCase(SampleCar.carList.get(i).getCarmake())) && (str2.equalsIgnoreCase(SampleCar.carList.get(i).getCarmodel()))) {
                    Display(SampleCar.carList.get(i));
                    searchindex = i;
                }
            }
        }
        if(searchindex == -1){
            System.out.println("Not found !!");
        }
    }



    public static void Display(Cars car)
    {
        User.car = car;
        System.out.println("The Reg.Number is: "+car.getRegname());
        System.out.println("The Year-made is: "+car.getYear());
        System.out.println("The Colour-1 is: "+car.getColor1());
        System.out.println("The Colour-2 is: "+car.getColor2());
        System.out.println("The Colour-3 is: "+car.getColor3());
        System.out.println("The CarMake is: "+car.getCarmake());
        System.out.println("The CarModel is: "+car.getCarmodel());
        System.out.println("The Price is: "+car.getPrice());
    }
    public static Cars add()
    {
        int i;
        Cars tempCar = new Cars();
        String tempString = null;
        int tempInt;
        Scanner input = new Scanner(System.in);
        while(true){
            System.out.println("Enter Reg. Number :");
            tempString = input.nextLine();
            for( i = 0; i < SampleCar.carList.size() ; i++){
                if(SampleCar.carList.get(i).getRegname().equalsIgnoreCase(tempString)){
                    System.out.println("This Registration Number is Taken,Please Try a New One !!");
                    break;
                }
            }
            if(i == SampleCar.carList.size()){
                break;
            }
        }
        tempCar.setRegname(tempString);
        System.out.println("Enter YearMade :");
        tempInt = input.nextInt();
        input.nextLine();
        tempCar.setYear(tempInt);
        System.out.println("Enter Colour-1 :");
        tempString = input.nextLine();
        tempCar.setColor1(tempString);
        System.out.println("Enter Colour-2 :");
        tempString = input.nextLine();
        tempCar.setColor2(tempString);
        System.out.println("Enter Colour-3 :");
        tempString = input.nextLine();
        tempCar.setColor3(tempString);
        System.out.println("Enter Car Make :");
        tempString = input.nextLine();
        tempCar.setCarmake(tempString);
        System.out.println("Enter Car Model :");
        tempString = input.nextLine();
        tempCar.setCarmodel(tempString);
        System.out.println("Enter Price :");
        tempInt = input.nextInt();
        tempCar.setPrice(tempInt);
        return tempCar;
    }
    public static void delete()
    {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the Registration Number :");
        String str = input.nextLine();
        searchByReg(str,false);
    }
    public static void writeFile(Build Fcar)
    {
        String line = null;
        try {
            BufferedWriter bw = new BufferedWriter(new FileWriter("cars.txt"));
            for (int i = 0;i <Fcar.carList.size() ; i++) {
                line = Fcar.carList.get(i).getRegname() + "," + String.valueOf(Fcar.carList.get(i).getYear()) + ","
                        + Fcar.carList.get(i).getColor1() + "," + Fcar.carList.get(i).getColor2() + ","
                        + Fcar.carList.get(i).getColor3() + "," + Fcar.carList.get(i).getCarmake() + ","
                        + Fcar.carList.get(i).getCarmodel() + "," + String.valueOf(Fcar.carList.get(i).getPrice());
                bw.write(line);
                bw.write("\n");
            }
            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
