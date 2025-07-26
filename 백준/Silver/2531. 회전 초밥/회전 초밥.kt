import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

private val br = BufferedReader(InputStreamReader(System.`in`))
private var N = 0;
private var d = 0;
private var k = 0;
private var c = 0;
private lateinit var arr: Array<Int>
private lateinit var cnt: Array<Int>

fun main(){
    val l0 = br.readLine().split(" ")
    N = l0[0].toInt()
    d = l0[1].toInt()
    k = l0[2].toInt()
    c = l0[3].toInt()
    arr = Array(N){ 0 }
    cnt = Array(d+1){ 0 }

    for(i in 0 .. N-1) arr[i] = br.readLine().toInt()

    var curSushi = 0;
    for(i in 0 .. k-1){
        if(cnt[arr[i]] == 0) curSushi++;
        cnt[arr[i]]++;
    }

    var maxSushi = curSushi
    if(cnt[c] == 0) maxSushi++

    for(i in 0 .. N-1){
        val outI = i; val inI = (i+k)%N

        if(--cnt[arr[outI]] == 0) curSushi--
        if(cnt[arr[inI]]++ == 0) curSushi++

        if(cnt[c] == 0) maxSushi = max(maxSushi, curSushi+1)
        else maxSushi = max(maxSushi, curSushi)
    }

    println(maxSushi)
}