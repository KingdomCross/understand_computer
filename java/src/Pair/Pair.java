package Pair;

public class Pair<T> {
    private T first;
    private T second;

    public Pair() {
        first = null;
        second = null;
    }

    public Pair(final T first, final T second) {
        this.first = first;
        this.second = second;
    }

    public T getFirst() {
        return first;
    }

    public T getSecond() {
        return second;
    }

    public void setFirst(final T newValue) {
        first = newValue;
    }

    public void setSecond(final T newValue) {
        second = newValue;
    }
}