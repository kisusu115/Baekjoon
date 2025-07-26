import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

private val br = BufferedReader(InputStreamReader(System.`in`))

private var N: Int = 0
private lateinit var arr: IntArray
private lateinit var result: IntArray
private var length = 0;

fun main(){
    N = br.readLine().toInt()
    arr = IntArray(N)
    result = IntArray(N)

    val st = StringTokenizer(br.readLine())
    for(i in 0..N-1){
        arr[i] = st.nextToken().toInt()
        val idx = lowerBoundDesc(0, length, arr[i])
        result[idx] = arr[i]
        if (idx == length) length++
    }
    println(N-length)
}

fun lowerBoundDesc(start: Int, end: Int, target: Int): Int{
    var s = start; var e = end
    while(s<e){
        val mid = (s+e)/2
        if(result[mid] <= target) e = mid
        else s = mid+1
    }
    return s
}