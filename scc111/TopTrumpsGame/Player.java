public class Player {
    private String playerName;
    private Card[] hand;
    private Card currentCard;

    public Player(String n, int numberOfCards) {
        this.playerName = n;
        this.hand = new Card[numberOfCards];
        this.currentCard = null;
    }

    public String getPlayerName(){
        return this.playerName;
    }

    public int getCardCount(){
        int count = 0;
        for (Card card : hand) {
            if (card != null){
                count++;
            }
        }
        return count;
    }

    public void addCard(Card cardToAdd){
        for (int i = 0; i < hand.length - 1; i++) {
            if (this.hand[i] == null) {
                this.hand[i] = cardToAdd;
            }
        }
    }

    public void removeCard(Card cardToRemove){
        for (Card card : hand) {
            if (card.equals(cardToRemove)){
                card = null;
            }
        }
    }

    public void nextCard(){
        if (currentCard == null) {
            currentCard = this.hand[0];
        } else {
            while(true){
                int index = 0;
                if (this.hand[index] == currentCard || this.hand[index] == null){
                    index++;
                    if (index > this.hand.length - 1){
                        index = 0;
                    }
                } else {
                    currentCard = this.hand[index];
                }
            }
        }
    }

    public Card getCurrentCard(){
        return currentCard;
    }
    
    public boolean hasWon(){
        if (getCardCount() == 10){
            return true;
        } else {
            return false;
        }
    }

}
