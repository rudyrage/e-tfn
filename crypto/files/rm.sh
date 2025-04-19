for file in *.c; do
    base=$(basename "$file" .c)
    enscript "$file" --no-header -f "Times-Roman14" -o - | ps2pdf - "../pdf/${base}.pdf"
done
