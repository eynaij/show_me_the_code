def nms(dets, thresh):
    x1 = dets[:,0]
    y1 = dets[:,1]
    x2 = dets[:,2]
    y2 = dets[:,3]
    scores = dets[:,4]
    s = (x2 - x1 + 1) * (y2 - y1 + 1)
    order = scores.argsort()[::-1]
    keep = []

    while order.size > 0:
        idx = order[0]
        keep.append(idx)
        xx1 = np.maximum(x1[idx],x1[order[1:]])
        yy1 = np.maximum(y1[idx],y1[order[1:]])
        xx2 = np.minimux(x2[idx],x2[order[1:]])
        yy2 = np.minimum(y2[idx],y2[order[1:]])
        w = np.maximum(xx2 - xx1 + 1,0)
        h = np.maximum(yy2 - yy1 + 1,0)
        inter = w * h

        iou = inter / (s[index] + s[order[1:]] - inter)
        index = np.where(iou < thresh)[0]
        order = order[index + 1]
    return keep
    
def soft_nms(dets, thresh, type='gaussian'):
    x1 = dets[:,0]
    y1 = dets[:,1]
    x2 = dets[:,2]
    y2 = dets[:,3]
    scores = dets[:,4]
    s = (x2 - x1 + 1) * (y2 - y1 + 1)
    order = scores.argsort()[::-1]
    keep = []

    while order.size > 0:
        idx = order[0]
        keep.append(idx)
        xx1 = np.maximum(x1[idx],x1[order[1:]])
        yy1 = np.maximum(y1[idx],y1[order[1:]])
        xx2 = np.minimux(x2[idx],x2[order[1:]])
        yy2 = np.minimum(y2[idx],y2[order[1:]])
        w = np.maximum(xx2 - xx1 + 1,0)
        h = np.maximum(yy2 - yy1 + 1,0)
        inter = w * h

        iou = inter / (s[index] + s[order[1:]] - inter)

        order = order[1:]
        score = score[1:]
        if type == 'linear':
            index = np.where(iou>thresh)[0]
            scores[index] *= (1-iou)
        else:
            scores *= np.exp(-iou ** 2 / thresh)
        tmp = scores.argsort()[::-1]
        order = order[tmp]
        socres = scores[tmp]
    return keep

def drop_out(x, drop_prob):
    assert 0 <= drop_prob <= 1
    keep_prob = 1 - drop_prob
    if keep_prob == 0:
        return x.zeros_like()
    mask = nd.random.uniform(0,1,x.shape) < keep_prob
    return mask * x / keep_prob

