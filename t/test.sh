progname="$1"
shift
for tfile in "$@"; do
    echo CASE "$(basename "$tfile")"
    echo
    echo INPUT
    cat "$tfile"
    echo OUTPUT
    "$progname" <"$tfile"
done
