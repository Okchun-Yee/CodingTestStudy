using System;

public class Solution {
    public int solution(int[] schedules, int[,] timelogs, int startday)
    {
        int answer = 0;
        int n = schedules.Length;
        int timeCheck = 0;
        if(n > 1000) return -1;
        for(int i =0;i<n;i++){
            for(int j =0;j<7;j++){
                if(schedules[i] < 700 |
                schedules[i]> 1100||
                timelogs[i,j]<600||
                timelogs[i,j] >2359) return -1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int result = 0;
            if((schedules[i]+10)%100 >= 60) timeCheck = schedules[i] + 50;
            else timeCheck = schedules[i] + 10;
            for (int j = 0; j < 7; j++)
            {
                if (timeCheck < timelogs[i, j])
                {
                    if ((startday + j) % 7 != 6 && (startday + j) % 7 != 0)
                    {
                        //System.Console.WriteLine("Day " + (startday + j)%7+ " | " +schedules[i] + " | " + timelogs[i,j]);
                        result++;
                    }
                }
            }
            schedules[i] = 5 - result;
        }
        for (int i = 0; i < n; i++)
        {
            //System.Console.WriteLine(schedules[i]);
            if (schedules[i] >= 5) answer++;
        }

        return answer;
    }
}