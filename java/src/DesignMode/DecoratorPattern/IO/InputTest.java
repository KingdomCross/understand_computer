package DesignMode.DecoratorPattern.IO;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class InputTest {
    public static void main(String[] args) throws IOException {
        int c;
        try {
            LowerCaseInputStream in = new LowerCaseInputStream(new BufferedInputStream(new FileInputStream("/home/dean/.gitconfig")));

            while((c = in.read())> 0) {
                System.out.print((char)c);
            }

            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}