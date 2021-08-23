
public class ElectricPowerSwitch {
    public Switchable item;
    public boolean on;

    public ElectricPowerSwitch(Switchable item) {
        this.item = item;
        this.on = false;
    }
    
    public boolean isOn() {
        return this.on;
    }
    
    public boolean press(){
        boolean checkOn = isOn();
        if (checkOn) {
            item.turnOn();
            this.on = false;
            return true;
        } else {
            item.turnOff();
            this.on = true;
            return false;
        }
    }
}