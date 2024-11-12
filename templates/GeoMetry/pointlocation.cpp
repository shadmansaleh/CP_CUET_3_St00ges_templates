void do_the_honour() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int cross_product = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);

    if (cross_product == 0) {
        cout << "TOUCH" << endl;
    } else if (cross_product > 0) {
        cout << "LEFT" << endl;
    } else {
        cout << "RIGHT" << endl;
    }
}
