public class Category {
    private String name;
    private int value;

    public Category(String n, int v){
        this.name = n;
        this.value = v;
    }

    public String getName(){
        return this.name;
    }

    public int getValue(){
        return this.value;
    }
}
