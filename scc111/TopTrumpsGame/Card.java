public class Card {
    private String name;
    private Category[] categories;

    public Card(String name, int speed, int weight, int era, int legs, int wings){
        this.name = name;
        this.categories = new Category[5];
        this.categories[0] = new Category("Speed", speed);
        this.categories[1] = new Category("Weight", weight);
        this.categories[2] = new Category("Era", era);
        this.categories[3] = new Category("Legs", legs);
        this.categories[4] = new Category("Wings", wings);
    }

    public String getName(){
        return this.name;
    }

    public Category getCategory(String target){
        for (Category category : categories) {
            if (category.getName().equals(target)){
                return category;
            }
        }
        return null;
    }

    public boolean isBetterThan(Card otherCard, String category){
        if (otherCard.getCategory(category).getValue() < this.getCategory(category).getValue()){
            return true;
        } else {
            return false;
        }
    }
}
