import java.io.*;
import java.util.LinkedList;
import java.util.Collections;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));      
       
        String[] inp;
        int meetingCount = Integer.parseInt(br.readLine());
        
        LinkedList<MeetingTime> mt = new LinkedList<>();

        for(int i = 0; i < meetingCount; i++) {
             inp = br.readLine().split(" ");
            mt.add(new MeetingTime(Integer.parseInt(inp[0]), Integer.parseInt(inp[1])));
        }

        Collections.sort(mt);

        LinkedList<MeetingTime> result = new LinkedList<>();
        result.add(mt.removeFirst());
        for(int i = 1; i < meetingCount; i++) {
            MeetingTime temp = mt.removeFirst();
            if(result.getLast().getEndTime() <= temp.getStartTime()) result.add(temp);            
        }

        System.out.println(result.size());
        
        
        

        
    }

    
}

class MeetingTime implements Comparable<MeetingTime>{
    int startTime;
    int endTime;

    MeetingTime(int startTime, int endTime) {
        this.startTime = startTime;
        this.endTime = endTime;
    }
    public int getStartTime() {
        return startTime;
    }

    public int getEndTime() {
        return endTime;
    }

    @Override
    public int compareTo(MeetingTime o) {
        if(getEndTime() == o.getEndTime()) {
            return getStartTime() - o.getStartTime();
        }
        return getEndTime() - o.getEndTime();
    }
}

