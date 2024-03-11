public class Player {
    private String playerName;
    private Card[] hand;
    private Card currentCard;
    private int currentCardIndex;

    public Player(String n, int numberOfCards) {
        this.playerName = n;
        this.hand = new Card[numberOfCards];
        this.currentCard = null;
        this.currentCardIndex = 0;
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
        for (int i = 0; i < hand.length; i++) {
            if (hand[i] == null) {
                hand[i] = cardToAdd;
                return;
            }
        }
    }

    public void removeCard(Card cardToRemove){
        for (int i = 0; i < hand.length; i++) {
            if (hand[i] == cardToRemove){
                hand[i] = null;
                return;
            }
        }
    }

    public void nextCard(){
        if (currentCard == null) {
            currentCard = hand[0];
        } else {
            int index = currentCardIndex + 1;
            boolean not_found = true;
            while(not_found){
                if(hand[index] == null){
                    index++;
                    if (index > hand.length - 1){
                        index = 0;
                    }
                } else {
                    not_found = false;
                }
            }
            currentCard = hand[index];
            currentCardIndex = index;
            return;
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
