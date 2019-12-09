package Pair;

public class PairTest {
    public static void main(final String[] args) {
        final Pair<Integer> mm = new Pair<>(3, 4);
        System.out.println(mm.getFirst());
        System.out.println(mm.getSecond());

        final Pair<String> mm2 = new Pair<>("DEAN", "KELLY");
        System.out.println(mm2.getFirst());
        System.out.println(mm2.getSecond());

        final String[] a = { "Mary", "Kelly", "Dean", "Maksym" };
        final Pair<String> m = ArrayAlg.minmax(a);
        System.out.println(m.getFirst());
        System.out.println(m.getSecond());

        final Pair<String> m2 = ArrayAlgImprove.minmax(a);
        System.out.println(m2.getFirst());
        System.out.println(m2.getSecond());

        final String middle = ArrayAlg2.<String>getMiddle("XX", "YY", "XXZ");
        System.out.println(middle);

        final double mid = ArrayAlg2.getMiddle(12.4, 4.7, 5.8);
        System.out.println(mid);
    }
}