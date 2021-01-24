import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;
class Cars {
    private String regname;
    private int price;
    private int year;
    private String carmake;
    private String carmodel;
    private String color1;
    private String color2;
    private String color3;

    public Cars(String regname, int year, String color1, String color2, String color3, String carmake, String carmodel, int price) {
        this.regname = regname;
        this.price = price;
        this.year = year;
        this.carmake = carmake;
        this.carmodel = carmodel;
        this.color1 = color1;
        this.color2 = color2;
        this.color3 = color3;
    }

    public Cars() {

    }

    public String getRegname() {
        return regname;
    }

    public void setRegname(String regname) {
        this.regname = regname;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public String getCarmake() {
        return carmake;
    }

    public void setCarmake(String carmake) {
        this.carmake = carmake;
    }

    public String getCarmodel() {
        return carmodel;
    }

    public void setCarmodel(String carmodel) {
        this.carmodel = carmodel;
    }

    public String getColor1() {
        return color1;
    }

    public void setColor1(String color1) {
        this.color1 = color1;
    }

    public String getColor2() {
        return color2;
    }

    public void setColor2(String color2) {
        this.color2 = color2;
    }

    public String getColor3() {
        return color3;
    }

    public void setColor3(String color3) {
        this.color3 = color3;
    }
}
public class Build {


    private int Counter;
    public List<Cars> carList = new ArrayList();

    public void setCounter(int Counter) {
        this.Counter = Counter;
    }
    public int getCounter() {
        return Counter;
    }
    Build() {
        Counter = 0;
        ListingCar();
    }

    public void ListingCar()
    {
        String fileName = "cars.txt";


        String line = null;
        int i =0;

        try {
            FileReader fileReader =
                    new FileReader(fileName);

            BufferedReader br =
                    new BufferedReader(fileReader);

            while((line = br.readLine()) != null && i < 20) {
                this.carList.add(setCar(line));
                i++;
                this.setCounter(i);
            }
            br.close();
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }
    public Cars setCar(String str)
    {
        String [] temp = str.split(",");
        Cars DemoCar = new Cars();
        DemoCar.setRegname(temp[0]);
        DemoCar.setYear(Integer.parseInt(temp[1]));
        DemoCar.setColor1(temp[2]);
        DemoCar.setColor2(temp[3]);
        DemoCar.setColor3(temp[4]);
        DemoCar.setCarmake(temp[5]);
        DemoCar.setCarmodel(temp[6]);
        DemoCar.setPrice(Integer.parseInt(temp[7]));
        return DemoCar;
    }

    public void addCar(Cars obj)
    {

    }
    public void deleteCar(Cars obj)
    {

    }
    public void searchCar(Cars obj)
    {

    }
}
